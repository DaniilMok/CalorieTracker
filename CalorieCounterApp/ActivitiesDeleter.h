#pragma once
#include "DataBase.h" // Подключаем заголовочный файл DataBase.h

class ActivitiesDeleter
{
	private:
		DataBase& db; // Ссылка на объект базы данных
		void deleteByIdUI(); // Метод для пользовательского интерфейса удаления активности по ID
		void deleteAllUI(); // Метод для пользовательского интерфейса удаления всех активностей
	public:
		explicit ActivitiesDeleter(DataBase& db); // Конструктор, принимающий ссылку на объект базы данных
		bool deleteActivityById(int id); //
		bool deleteAllActivities(); // Метод для удаления всех активностей из базы данных
		void runDeleteUI(); // Метод для запуска пользовательского интерфейса удаления активностей
};

