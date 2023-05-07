#include <iostream>
#include <fstream>
#include <vector>
#include <locale>
#include <codecvt>
#include <list>
#include <algorithm>
#include <set>

using namespace std;

struct Record {
    int year;
    int month;
    int duration;
    int client_code;
};
int main()
{
    std::cout << "Lab 9. STL. \n";

    setlocale(LC_CTYPE, "ukr");

    int task_number;
    std::cout << "Выберiть завдання (1-3): ";
    cin >> task_number;

    switch (task_number) 
    {
    case 1: 
    {
        vector<Record> records;

        // Зчитуємо дані з файлу
        ifstream input("input.txt");
        int year, month, duration, client_code;
        while (input >> year >> month >> duration >> client_code) 
        {
            records.push_back({ year, month, duration, client_code });
            std::cout << year << " " << month << " " << duration << " " << client_code << "\n";
        }
        input.close();

        // розраховуємо загальну тривалість занять на кожен рік
        vector<int> total_durations(10000, 0); // за кожен рік від 1 до 9999
        for (const auto& record : records) 
        {
            total_durations[record.year] += record.duration;
        }

        // знаходимо рік з найдовшою загальною тривалістю
        int max_year = -1;
        int max_duration = -1;
        for (int year = 1; year <= 9999; ++year) 
        {
            if (total_durations[year] > max_duration) 
            {
                max_year = year;
                max_duration = total_durations[year];
            }
        }

        // записуємо результат у файл
        ofstream output("output.txt");
        output << max_year << " " << max_duration << endl;
        output.close();

        break;
    }
    case 2: 
    {
        std::list<int> L = { 2, 4, 0, 1, 3, 8, 234, 0};

        std::cout << "Вхiдний список: ";
        for (int num : L) {
            std::cout << num << " ";
        }
        std::cout << std::endl;

        auto firstZero = std::find(L.begin(), L.end(), 0);

        if (firstZero != L.end())
        {
            L.erase(firstZero);

            auto lastZero = std::find(std::make_reverse_iterator(L.end()), std::make_reverse_iterator(L.begin()), 0).base();

            if (lastZero != L.begin()) 
            {
                L.erase(prev(lastZero));
            }
        }

        std::cout << "Вихiдний список: ";
        for (int num : L) {
            std::cout << num << " ";
        }
        std::cout << std::endl;

        break;
    }
    case 3: 
    {

        std::vector<int> v0 = { 1, 2, 3, 3, 4 }; // вхідний вектор
        std::vector<std::vector<int>> v = { {1, 2, 3}, {2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 3, 4}, {1, 2, 3, 3, 4, 5, 6} }; // вектори V1, ..., VN

        int count = 0; // кількість векторів, які вміщують всі елементи початкового вектора

        std::multiset<int> s0(v0.begin(), v0.end()); // мультисет на основі початкового вектора

        for (const auto& vi : v) 
        {
            std::multiset<int> si(vi.begin(), vi.end()); // мультисет на основі наступного vi

            if (std::includes(si.begin(), si.end(), s0.begin(), s0.end())) 
            {
                count++;
            }
        }

        std::cout << "Кiлькiсть векторiв VI, якi вмiщують всi елементи початкового вектора: " << count << std::endl;

        break;
    }
    default: 
    {
        cout << "Нема такого завдання, виберіть інше !!! " << endl;
        break;
    }

    }

}
