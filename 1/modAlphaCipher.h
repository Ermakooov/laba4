/** @file modAlphaCipher.h
 * @author Ермаков Н.А.
 * @version 1.0
 * @date 19.12.2024
 * @copyright ИБСТ ПГУ
 * @warning Это учебный пример
 * @brief Заголовочный файл для модуля Гронсвельда
 */
#pragma once
#include <map>
#include <string>
#include <vector>
#include <stdexcept>
#include <locale>
#include <codecvt>
/** @brief Шифрование методом Гронсвельда
 * @details Ключ устанавливается в конструкторе.
 * Для зашифровывания и расшифровывания предназначены методы encrypt и decrypt.
 * @warning Реализация только для русского языка
 */
class modAlphaCipher
{
private:
    std::wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";///<Алфавит по порядку
    std::map<wchar_t, int> alphaNum; ///< Ассоциативный массив"номер по символу"
    std::vector<int> key; ///< Ключ
    std::vector<int> convert(const std::wstring& s);///< Преобразование строки в вектор
    std::wstring convert(const std::vector<int>& v);///< Преобразование вектора в строку
    /**
 * @brief Валидация ключа
 *
 * Проверяет, что ключ не пустой и не содержит символов, не принадлежащих алфавиту.
 * @param s Входная строка, представляющая ключ.
 * @throw cipher_error Если ключ пустой или содержит
недопустимые символы.
 */
    std::wstring getValidKey(const std::wstring & s);
    /**
 * @brief Валидация открытого текста
 *
 * Проверяет, что открытый текст содержит только
допустимые символы алфавита.
 * @param s Входная строка, представляющая открытый текст.
 * @throw cipher_error Если открытый текст содержит недопустимые символы.
 */
    std::wstring getValidOpenText(const std::wstring& s);
    /**
 * @brief Валидация зашифрованного текста
 *
 * Проверяет, что зашифрованный текст содержит только
допустимые символы алфавита.
 *
 * @param s Входная строка, представляющая зашифрованныйтекст.
 * @throw cipher_error Если зашифрованный текст содержит недопустимые символы.
 */
    std::wstring getValidCipherText(const std::wstring& s);
public:
    modAlphaCipher() = delete;  ///< Запрет на использование конструктора по умолчанию
    /**
     * @brief Конструктор с параметром
     * @param skey Ключ для шифрования/расшифрования
     * @throw cipher_error Если ключ невалидный
     */
    modAlphaCipher(const std::wstring& skey);
    /**
     * @brief Метод для зашифровывания
     * @param open_text Открытый текст
     *Строчные символы автоматически преобразуются к прописным.
 	 * Все символы, не являющиеся буквами, удаляются
     * @throw cipher_error Если открытый текст невалидный
     * @return Зашифрованный текст
     */
    std::wstring encrypt(const std::wstring& open_text);
     /**
     * @brief Метод для расшифрования
     * @param cipher_text Зашифрованный текст
     * @throw cipher_error Если зашифрованный текст невалидный
     * @return Расшифрованный текст
     */
    std::wstring decrypt(const std::wstring& cipher_text);
};
/**
 * @brief Обработка исключений
 *Класс,созданный для обработки ошибок
 * @details Наследуется от std::invalid_argument
 */
class cipher_error : public std::invalid_argument
{
public:
	/**
     * @brief Конструктор с параметром типа const std::string
     * @param what_arg Описание ошибки
     */
    explicit cipher_error(const std::string& what_arg):
        std::invalid_argument(what_arg) {}
     /**
     * @brief Конструктор с параметром типа const char
     * @param what_arg Описание ошибки
     */
    explicit cipher_error(const char* what_arg):
        std::invalid_argument(what_arg) {}
};
