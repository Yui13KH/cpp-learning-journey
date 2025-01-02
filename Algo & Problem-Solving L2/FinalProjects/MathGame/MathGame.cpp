/*
 * Math Game
 * 
 * 1. Setup and Initialization
 *      Ask for difficulty level: Use an enum to represent difficulty levels (EASY, MEDIUM, ADVANCED, HARD, EXTREME). This makes it more readable and easier to manage.
 *      Ask for number of questions: Validate user input to ensure it is a positive number.
 *      Seed the random number generator (srand) to ensure varied question generation.
 * 2. Question Generation
 *      Rules Based on Difficulty:
 *      
 *      EASY: Addition/subtraction, single-digit numbers.
 *      MEDIUM: Addition/subtraction/multiplication, double-digit numbers.
 *      ADVANCED: Include division with integer results.
 *      HARD: Mixed operations and multi-step problems.
 *      EXTREME: Introduce powers, roots, or combined operations.
 *      Precompute the correct answer for each question and store it.
 * 3. Gameplay Loop
 *      Generate each question and display it.
 *      Get the user's input and check against the precomputed answer.
 *      Use ANSI escape codes for red (wrong answer) and green (correct answer) output.
 * 4. End-of-Game Results
 *      Calculate the number of correct and incorrect answers.
 *      Compute success percentage.
 *      Use an English grading system (A-F) based on the percentage:
 *          A: 90-100%
 *          B: 80-89%
 *          C: 70-79%
 *          D: 60-69%
 *          F: Below 60%
 *      Display the results in a well-formatted way.
 * 5. Optional Enhancements
 *      High Score System:
 *          Store the high score in a struct with fields for difficulty level, percentage, and total questions.
 *          Reset scores when the program ends or maintain them only during the runtime.
 *      Advanced Formatting:
 *          Display results in a table format for clarity.
 *      Timed Mode:
 *          Introduce a timer to track how quickly the player answers questions.
 * 
 * Extend the Menu for Operation Selection
 * Add a new prompt where the user can choose the type of operations they want in the questions.
 * Use an enum for the available operations: enum OperationType { ADD, SUBTRACT, MULTIPLY, DIVIDE };
 * 
 * Ideas for Improvement
 * Add Random Math Challenges:
 *      Include special challenges like “Solve in X seconds”
 * Support for Multiple Users:
 *      Allow players to input their names and save scores for each player during the session.
 * Leaderboard:
 *      Show a leaderboard during the runtime.
 */
