#include <clocale>  // <-- добавили для setlocale
#include <iostream>

// Константы (требование задания: без "магических чисел")
namespace {
const int MINUTES_IN_HOUR = 60;
const int HOURS_IN_DAY = 24;

const int MORNING_START = 5;
const int DAY_START = 12;
const int EVENING_START = 18;

const int NOON_HOUR = 12;
const int NOON_MINUTE = 0;
const int MIDNIGHT_HOUR = 0;
const int MIDNIGHT_MINUTE = 0;

const int MOD_10_ONE = 1;
const int MOD_10_TWO = 2;
const int MOD_10_FOUR = 4;
const int MOD_100_TEEN_START = 11;
const int MOD_100_TEEN_END = 14;
const int MOD_100 = 100;
const int MOD_10 = 10;

const int LAST_HOUR_OF_DAY = 23;
}  // namespace

void printHours(int hours) {
    int lastDigit = hours % MOD_10;
    int lastTwoDigits = hours % MOD_100;

    if (lastTwoDigits >= MOD_100_TEEN_START && lastTwoDigits <= MOD_100_TEEN_END) {
        std::cout << hours << " часов";
    } else if (lastDigit == MOD_10_ONE) {
        std::cout << hours << " час";
    } else if (lastDigit >= MOD_10_TWO && lastDigit <= MOD_10_FOUR) {
        std::cout << hours << " часа";
    } else {
        std::cout << hours << " часов";
    }
}

void printMinutes(int minutes) {
    int lastDigit = minutes % MOD_10;
    int lastTwoDigits = minutes % MOD_100;

    if (lastTwoDigits >= MOD_100_TEEN_START && lastTwoDigits <= MOD_100_TEEN_END) {
        std::cout << minutes << " минут";
    } else if (lastDigit == MOD_10_ONE) {
        std::cout << minutes << " минута";
    } else if (lastDigit >= MOD_10_TWO && lastDigit <= MOD_10_FOUR) {
        std::cout << minutes << " минуты";
    } else {
        std::cout << minutes << " минут";
    }
}

int main() {
    std::setlocale(LC_ALL, "Russian");  // <-- добавили для русского языка

    int hours, minutes;

    std::cout << "Введите часы и минуты (например, 2 48): ";
    std::cin >> hours >> minutes;

    if (hours < 0 || hours >= HOURS_IN_DAY || minutes < 0 || minutes >= MINUTES_IN_HOUR) {
        std::cout << hours << " " << minutes << " - введены недопустимые данные" << std::endl;
        return 1;
    }

    if (hours == NOON_HOUR && minutes == NOON_MINUTE) {
        std::cout << hours << " " << minutes << " - полдень" << std::endl;
        return 0;
    }
    if (hours == MIDNIGHT_HOUR && minutes == MIDNIGHT_MINUTE) {
        std::cout << hours << " " << minutes << " - полночь" << std::endl;
        return 0;
    }

    std::cout << hours << " " << minutes << " - ";
    printHours(hours);
    std::cout << " ";
    printMinutes(minutes);
    std::cout << " ";

    if (hours >= MORNING_START && hours < DAY_START) {
        std::cout << "утра";
    } else if (hours >= DAY_START && hours < EVENING_START) {
        std::cout << "дня";
    } else if (hours >= EVENING_START && hours <= LAST_HOUR_OF_DAY) {
        std::cout << "вечера";
    } else {
        std::cout << "ночи";
    }

    std::cout << std::endl;
    return 0;
}
