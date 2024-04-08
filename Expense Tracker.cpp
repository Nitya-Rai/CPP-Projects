#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Expense class to represent individual expenses
class Expense {
private:
    string category;
    double amount;
    string description;
    string date;

public:
    Expense(const string& cat, double amt, const string& desc, const string& dt)
        : category(cat), amount(amt), description(desc), date(dt) {}

    // Display the details of the expense
    void display() const {
        cout << "Date: " << date << ", Category: " << category << ", Amount: $" << fixed << setprecision(2) << amount << ", Description: " << description << endl;
    }

    // Get the amount of the expense
    double getAmount() const {
        return amount;
    }
};

// ExpenseTracker class to manage multiple expenses
class ExpenseTracker {
private:
    vector<Expense> expenses;

public:
    // Add new expense to the tracker
    void addExpense(const Expense& expense) {
        expenses.push_back(expense);
        cout << "Expense added successfully." << endl;
    }

    // Display all expenses in the tracker
    void displayExpenses() const {
        if (expenses.empty()) {
            cout << "No expenses recorded yet." << endl;
            return;
        }
        cout << "All Expenses:" << endl;
        for (const Expense& expense : expenses) {
            expense.display();
        }
    }

    // Display total expenses
    void displayTotalExpenses() const {
        if (expenses.empty()) {
            cout << "No expenses recorded yet." << endl;
            return;
        }
        double total = 0.0;
        for (const Expense& expense : expenses) {
            total += expense.getAmount();
        }
        cout << "Total Expenses: " << fixed << setprecision(2) << total << endl;
    }
};

int main() {
    ExpenseTracker tracker;
    char choice;

    do {
        cout << "Select an option:" << endl;
        cout << "1. Add Expense" << endl;
        cout << "2. Display All Expenses" << endl;
        cout << "3. Display Total Expenses" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear the newline character from the input buffer

        switch (choice) {
            case '1': {
                string category, description, date;
                double amount;

                cout << "Enter expense details:" << endl;
                cout << "Category: ";
                getline(cin, category);
                cout << "Amount: ";
                cin >> amount;
                cin.ignore(); // Clear the newline character from the input buffer
                cout << "Description: ";
                getline(cin, description);
                cout << "Date (optional, press Enter if not applicable, YYYY-MM-DD): ";
                getline(cin, date);

                if (date.empty()) {
                    // Add expense without date
                    tracker.addExpense(Expense(category, amount, description, "N/A"));
                } else {
                    // Add expense with date
                    tracker.addExpense(Expense(category, amount, description, date));
                }
                break;
            }
            case '2':
                tracker.displayExpenses();
                break;
            case '3':
                tracker.displayTotalExpenses();
                break;
            case '4':
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != '4');

    return 0;
}
