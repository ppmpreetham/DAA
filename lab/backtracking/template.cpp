void backtrack(params) {
    if (base_case_condition) {
        results.push_back(copy_of_solution);
        return;
    }

    for (auto choice : choices) {
        if (violates_constraints(choice))
            continue;

        make_choice(choice);
        backtrack(updated_params);
        undo_choice(choice); // backtracking step
    }
}
