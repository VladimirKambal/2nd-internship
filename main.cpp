#include "book.h"

#include <iostream>
#include <stdexcept>

int main()
{
    try
    {
        // Создаём книгу
        Book book(
            "The Great Gatsby",
            "F. Scott Fitzgerald",
            1925,
            180
        );

        std::cout << "Initial book:\n";
        std::cout << formatBookInfo(book) << "\n\n";
        // Часть 1. Проверка сеттера года
        std::cout << "Trying to update year to 3000...\n";

        try
        {
            book.updateYear(3000);
        }
        catch (const std::invalid_argument& e)
        {
            std::cout << "Exception caught: "
                      << e.what()
                      << "\n\n";
        }
        // Успешное обновление названия
        book.updateTitle("The Great Gatsby - Updated");

        std::cout << "Title successfully updated:\n";
        std::cout << formatBookInfo(book) << "\n\n";
        // Классические книги
        if (isClassic(book))
        {
            std::cout << "The book is a classic.\n";
        }
        else
        {
            std::cout << "The book is not a classic.\n";
        }


        // Dремя чтения
        int pages_per_day = 30;

        double days = readingTime(book, pages_per_day);

        std::cout << "Reading time: "
                  << days
                  << " days\n\n";

        // Создаём вторую книгу
        Book secondBook(
            "1984",
            "George Orwell",
            1949,
            328
        );
        // Cравнение книг
        if (isOlder(book, secondBook))
        {
            std::cout << "\"" << book.getTitle()
                      << "\" is older than \""
                      << secondBook.getTitle()
                      << "\".\n";
        }
        else
        {
            std::cout << "\"" << book.getTitle()
                      << "\" is not older than \""
                      << secondBook.getTitle()
                      << "\".\n";
        }
        // Управление состоянием книги
        std::cout << "\nBefore checkout:\n";
        std::cout << formatBookInfo(book) << "\n";

        book.checkout();

        std::cout << "\nAfter checkout:\n";
        std::cout << formatBookInfo(book) << "\n";

        book.returnBook();

        std::cout << "\nAfter returning:\n";
        std::cout << formatBookInfo(book) << "\n";
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << "Error: "
                  << e.what()
                  << "\n";
    }

    std::cout << "\nPress Enter to exit...";
    std::cin.get();
    return 0;
}