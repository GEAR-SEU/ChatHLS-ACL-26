Top-Level Function: `viterbi`

Complete Function Signature of the Top-Level Function:
`int viterbi(tok_t obs[N_OBS], prob_t init[N_STATES], prob_t transition[N_STATES * N_STATES], prob_t emission[N_STATES * N_TOKENS], state_t path[N_OBS])`

Inputs:
- `obs`: an array of `N_OBS` tokens, each of type `tok_t` (uint8_t), representing the sequence of observations.
- `init`: an array of `N_STATES` initial probabilities, each of type `prob_t` (double), representing the probability of being in each state initially.
- `transition`: a 2D array of `N_STATES` x `N_STATES` transition probabilities, each of type `prob_t` (double), representing the probability of transitioning from one state to another.
- `emission`: a 2D array of `N_STATES` x `N_TOKENS` emission probabilities, each of type `prob_t` (double), representing the probability of observing a token in each state.
- `path`: an array of `N_OBS` states, each of type `state_t` (uint8_t), to store the most likely state sequence.

Outputs:
- `path`: the most likely state sequence, stored in the input array.

Important Data Structures and Data Types:
- `prob_t`: a double-precision floating-point type used to represent probabilities in -log space.
- `tok_t`: an unsigned 8-bit integer type used to represent tokens.
- `state_t`: an unsigned 8-bit integer type used to represent states.
- `step_t`: a 32-bit signed integer type used to represent time steps.
- `llike`: a 2D array of `N_OBS` x `N_STATES` probabilities, each of type `prob_t`, used to store the likelihood of being in each state at each time step.

Sub-Components:
- `L_init`: a loop that initializes the likelihood array with the first observation and initial probabilities.
- `L_timestep`: a loop that iteratively computes the probabilities over time.
- `L_curr_state`: a loop that computes the likelihood of being in each state at each time step.
- `L_prev_state`: a loop that computes the likelihood of transitioning from each previous state to the current state.
- `L_end`: a loop that identifies the end state with the highest probability.
- `L_backtrack`: a loop that backtracks to recover the full path by finding the most likely previous state at each time step.