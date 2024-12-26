/** @file tableCipher.h
 * @author Ермаков Н.А.
 * @version 1.0
 * @date 19.12.2024
 * @copyright ИБСТ ПГУ
 * @warning Это учебный пример
 * @brief Заголовочный файл для модуля маршрутной перестановки
 */
#pragma once
#include <cctype>
#include <codecvt>
#include <iostream>
#include <locale>
#include <map>
#include <string>
#include <vector>
/**
 * @class TableCipher
 * @brief Шифрование методом маршрутной перестановки
 * 
 * Класс TableCipher предоставляет методы для зашифрования и расшифрования текста с использованием табличного шифра.
 * Ключ для зашифрования и расшифрования должен быть положительным целым числом.
 */
class TableCipher
{
private:
    int stolb; ///< Ключ, используемый для зашифрования и расшифрования
     /**
     * @brief Проверка ключа на валидность.
     * 
     * Метод проверяет, является ли ключ положительным целым числом.
     * 
     * @param key Ключ, который нужно проверить.
     * @return Валидный ключ.
     * @throw cipher_error Если ключ не является положительным целым числом.
     */
    int getValidKey(const int& key);//  проверка ключа на валидности
    /**
     * @brief Проверка текста на валидность.
     * 
     * Метод проверяет, содержит ли текст только буквы алфавита.
     * 
     * @param text Текст, который нужно проверить.
     * @return  Валидный текст.
     * @throw cipher_error Если текст содержит недопустимые символы.
     */
    std::wstring getValidText(const std::wstring& text);// проверка текста на валидности
public:
	TableCipher() = delete; //< Запрет на конструктор по умолчанию.
	/**
     * @brief Конструктор с параметрами 
     * 
     * Создает объект TableCipher с указанным ключом.
     * 
     * @param key Ключ для шифрования и дешифрования.
     * @throw cipher_error Если ключ не является положительным целым числом.
     */
    TableCipher(const int& key);
    /**
     * @brief Метод для шифрования текста.
     * 
     * Шифрует текст с использованием табличного шифра и ключа, указанного при создании объекта.
     * 
     * @param encrypt_text Текст, который нужно зашифровать.
     * @return Зашифрованный текст.
     * @throw cipher_error Если текст содержит недопустимые символы.
     */
    std::wstring encrypt(const std::wstring& encrypt_text);
     /**
     * @brief Метод для расшифровки текста.
     * 
     * Расшифровывает текст с использованием табличного шифра и ключа, указанного при создании объекта.
     * 
     * @param decrypt_text Текст, который нужно расшифровать.
     * @return Расшифрованный текст.
     * @throw cipher_error Если текст содержит недопустимые символы.
     */
    std::wstring decrypt(const std::wstring& decrypt_text);
};
/**
 * @class cipher_error
 * @brief Обработка исключений.
 * 
 * Класс cipher_error наследуется от std::invalid_argument и используется для обработки ошибок,возникающих при некорректных входных данных (например, невалидный ключ или текст).
 */
class cipher_error : public std::invalid_argument
{
public:
	/**
     * @brief Конструктор с параметром типа const std::string.
     * 
     * Создает объект исключения с указанным сообщением об ошибке.
     * 
     * @param what_arg Сообщение об ошибке.
     */
    explicit cipher_error(const std::string& what_arg):
        std::invalid_argument(what_arg) {}
    /**
     * @brief Конструктор с параметром типа const char.
     * 
     * Создает объект исключения с указанным сообщением об ошибке.
     * 
     * @param what_arg Сообщение об ошибке.
     */
    explicit cipher_error(const char* what_arg):
        std::invalid_argument(what_arg) {}
};
