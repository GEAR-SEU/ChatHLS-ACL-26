#include <iostream>
#include <fstream>
#include <iomanip>
#include <cfloat>
#include <vector>
#include <string>
#include <map>
#include <cstring>
#include <dirent.h>
#include "mobilenet.h"

void mobilenet_hw(
	int image_in_stream[INPUT_IMG_SIZE],
	int prediction[NUM_CLASSES]
);

bool read_image_from_file(const std::string& file_path, int* image_data) {
    std::ifstream infile(file_path);
    if (!infile.is_open()) {
        std::cerr << "ERROR: Cannot open input file: " << file_path << std::endl;
        return false;
    }

    unsigned int temp_hex_val;
    for (int i = 0; i < INPUT_IMG_SIZE; ++i) {
        if (!(infile >> std::hex >> temp_hex_val)) {
            std::cerr << "ERROR: File format error or file is too short in " << file_path << std::endl;
            infile.close();
            return false;
        }
        image_data[i] = (int)temp_hex_val;
    }
    infile.close();
    return true;
}


int main() {
	const std::string base_path = "C:/Users/fd_reality/Desktop/mobilenet/output_image_hex_norm/";

    const std::map<std::string, int> class_to_label_map = {
        {"collapsed_building", 0},
        {"fire",               1},
        {"flooded_areas",      2},
        {"normal",             3},
        {"traffic_incident",   4}
    };

    static int image_data[INPUT_IMG_SIZE];
    static int prediction[NUM_CLASSES];

    int total_images_processed = 0;
    int correct_predictions = 0;

    std::cout << "--- STARTING BATCH TEST ---" << std::endl;
    std::cout << "INFO: Base Directory: " << base_path << std::endl;

    for (const auto& pair : class_to_label_map) {
        const std::string& class_name = pair.first;
        const int expected_label = pair.second;

        std::string class_dir_path_str = base_path + class_name;

        DIR *dir;
        struct dirent *ent;
        if ((dir = opendir(class_dir_path_str.c_str())) != NULL) {
            while ((ent = readdir(dir)) != NULL) {
                if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
                    continue;
                }

                std::string filename = ent->d_name;
                if (filename.length() > 4 && filename.substr(filename.length() - 4) == ".txt") {
                    std::string current_file_path = class_dir_path_str + "/" + filename;
                    total_images_processed++;

                    if (!read_image_from_file(current_file_path, image_data)) {
                        std::cerr << "ERROR: Failed to read image data for " << current_file_path << ". Skipping." << std::endl;
                        continue;
                    }

                    mobilenet_hw(image_data, prediction);

                    float max_val = -FLT_MAX;
                    int predicted_label = -1;
                    for (int i = 0; i < NUM_CLASSES; ++i) {
                        if (prediction[i] > max_val) {
                            max_val = prediction[i];
                            predicted_label = i;
                        }
                    }

                    if (predicted_label == expected_label) {
                        correct_predictions++;
                    }
                }
            }
            closedir(dir);
        } else {
            std::cerr << "WARNING: Could not open directory. Skipping: " << class_dir_path_str << std::endl;
        }
    }

    std::cout << "\n\n========================================" << std::endl;
    std::cout << "--- BATCH TEST SUMMARY ---" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Total Images Processed: " << total_images_processed << std::endl;
    std::cout << "Correct Predictions:    " << correct_predictions << std::endl;

    if (total_images_processed > 0) {
        double accuracy = (double)correct_predictions / total_images_processed * 100.0;
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Accuracy:               " << accuracy << "%" << std::endl;
    } else {
        std::cout << "No images were found to process. Check your paths and file structure." << std::endl;
    }
    std::cout << "========================================" << std::endl;

    std::cout << "\n--- TEST FINISHED ---" << std::endl;
    return 0;
}
