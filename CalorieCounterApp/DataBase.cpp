#include "DataBase.h" // Указывает относительный путь к DataBase.h
#include <iostream> // Указывает относительный путь к iostream
#include <vector> // Указывает относительный путь к vector для работы с векторами

using namespace std; // Пространство имен std для удобства

DataBase::DataBase(const char* filename) { // Конструктор принимает имя файла базы данных
	if (sqlite3_open(filename, &db)) { // Открываем базу данных
		cerr << "Ошибка подключения: " << sqlite3_errmsg(db) << "\n"; // Если не удалось открыть базу данных, выводим сообщение об ошибке
		db = nullptr; // Устанавливаем указатель на базу данных в nullptr
    }
}

DataBase::~DataBase() { // Деструктор закрывает базу данных
	if (db) sqlite3_close(db); // Если база данных открыта, закрываем ее
}

bool DataBase::createTableUsers() { // Функция для создания таблицы пользователей
	// SQL-запрос для создания таблицы продуктов, если она не существует
	const char* sql = R"(
		CREATE TABLE IF NOT EXISTS users (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL,
			gender TEXT NOT NULL,
			years REAL,
			growth REAL,
			weight REAL,
			activity_type TEXT NOT NULL,
			food_type TEXT NOT NULL
		);
	)";
	char* errMsg = nullptr; // Переменная для хранения сообщения об ошибке
	int rc = sqlite3_exec(db, sql, nullptr, nullptr, &errMsg); // Выполняем SQL-запрос
	if (rc != SQLITE_OK) { // Если запрос не выполнен успешно
		cerr << "Ошибка создания таблицы: " << errMsg << "\n"; // Выводим сообщение об ошибке
		sqlite3_free(errMsg); // Освобождаем память, занятую сообщением об ошибке
		return false; // Возвращаем false, если таблица не создана
	}
	return true; // Возвращаем true, если таблица успешно создана
}

int DataBase::isUserExists(int actualCount) {
	const char* sql = R"(
		SELECT COUNT(*) FROM users;
	)";
	sqlite3_stmt* stmt = nullptr; // Указатель на подготовленный SQL-запрос
	if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
		cerr << "Ошибка подготовки запроса: " << sqlite3_errmsg(db) << "\n";
		return -1;
	}
	sqlite3_bind_int(stmt, 1, actualCount);
	if (sqlite3_step(stmt) != SQLITE_ROW) {
		cerr << "Ошибка выполнения запроса: " << sqlite3_errmsg(db) << "\n";
		sqlite3_finalize(stmt);
		return -1;
	}
	actualCount = sqlite3_column_int(stmt, 0); // Переменная для хранения количества пользователей
	sqlite3_finalize(stmt); // Освобождаем подготовленный запрос
	if (actualCount == 0) { // Если количество пользователей равно 0
		return actualCount; // Возвращаем 0, если пользователь не найден
	} 
	else if (actualCount == 1) {
		return actualCount; // Возвращаем 1, если пользователь найден
	}
	else if (actualCount > 1) {
		return actualCount; // Возвращаем количество найденных пользователей
	}
	else {
		return -1; // Возвращаем -1 в случае неизвестной ошибки
	}
}

bool DataBase::createTableInfoUsers() {
	const char* sql = R"(
		CREATE TABLE IF NOT EXISTS usersInfo (
			id INTEGER PRIMARY KEY AUTOINCREMENT,
			number REAL NOT NULL,
            name TEXT NOT NULL,
			gender TEXT NOT NULL,
			daily_ccal_intake REAL NOT NULL,
			use_ccal REAL NOT NULL,
			burn_ccal_in_activity REAL,
			weight REAL,
			days_with_a_successfully_completed_plan REAL,
			date_of_achievement DATE,
			FOREIGN KEY (id) REFERENCES users(id)
		);
	)";
	char* errMsg = nullptr; // Переменная для хранения сообщения об ошибке
	int rc = sqlite3_exec(db, sql, nullptr, nullptr, &errMsg); // Выполняем SQL-запрос
	if (rc != SQLITE_OK) { // Если запрос не выполнен успешно
		cerr << "Ошибка создания таблицы: " << errMsg << "\n"; // Выводим сообщение об ошибке
		sqlite3_free(errMsg); // Освобождаем память, занятую сообщением об ошибке
		return false; // Возвращаем false, если таблица не создана
	}
	return true; // Возвращаем true, если таблица успешно создана
}

bool DataBase::createTableUserActivities() { // Функция для создания таблицы активностей пользователей
	// SQL-запрос для создания таблицы активностей пользователей, если она не существует
	const char* sql = R"(
		CREATE TABLE IF NOT EXISTS userActivities (
			id INTEGER PRIMARY KEY AUTOINCREMENT,
			user_id INTEGER NOT NULL,
			activity_id INTEGER NOT NULL,
			duration REAL NOT NULL,
			FOREIGN KEY (user_id) REFERENCES users(id),
			FOREIGN KEY (activity_id) REFERENCES activities(id)
		);
	)";
	char* errMsg = nullptr; // Переменная для хранения сообщения об ошибке
	int rc = sqlite3_exec(db, sql, nullptr, nullptr, &errMsg); // Выполняем SQL-запрос
	if (rc != SQLITE_OK) { // Если запрос не выполнен успешно
		cerr << "Ошибка создания таблицы: " << errMsg << "\n"; // Выводим сообщение об ошибке
		sqlite3_free(errMsg); // Освобождаем память, занятую сообщением об ошибке
		return false; // Возвращаем false, если таблица не создана
	}
	return true; // Возвращаем true, если таблица успешно создана
}

bool DataBase::createTableUserProducts() { // Функция для создания таблицы продуктов пользователей
	// SQL-запрос для создания таблицы продуктов пользователей, если она не существует
	const char* sql = R"(
		CREATE TABLE IF NOT EXISTS userProducts (
			id INTEGER PRIMARY KEY AUTOINCREMENT,
			user_id INTEGER NOT NULL,
			product_id INTEGER NOT NULL,
			quantity REAL NOT NULL,
			FOREIGN KEY (user_id) REFERENCES users(id),
			FOREIGN KEY (product_id) REFERENCES products(id)
		);
	)";
	char* errMsg = nullptr; // Переменная для хранения сообщения об ошибке
	int rc = sqlite3_exec(db, sql, nullptr, nullptr, &errMsg); // Выполняем SQL-запрос
	if (rc != SQLITE_OK) { // Если запрос не выполнен успешно
		cerr << "Ошибка создания таблицы: " << errMsg << "\n"; // Выводим сообщение об ошибке
		sqlite3_free(errMsg); // Освобождаем память, занятую сообщением об ошибке
		return false; // Возвращаем false, если таблица не создана
	}
	return true; // Возвращаем true, если таблица успешно создана
}

bool DataBase::createTableProducts() { // Функция для создания таблицы продуктов
	// SQL-запрос для создания таблицы продуктов, если она не существует
    const char* sql = R"(
        CREATE TABLE IF NOT EXISTS products (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL,
            kcal_per_100g REAL NOT NULL,
            protein REAL,
            fat REAL,
            carbs REAL
        );
    )";
	char* errMsg = nullptr; // Переменная для хранения сообщения об ошибке
	int rc = sqlite3_exec(db, sql, nullptr, nullptr, &errMsg); // Выполняем SQL-запрос
	if (rc != SQLITE_OK) { // Если запрос не выполнен успешно
		cerr << "Ошибка создания таблицы: " << errMsg << "\n"; // Выводим сообщение об ошибке
		sqlite3_free(errMsg); // Освобождаем память, занятую сообщением об ошибке
		return false; // Возвращаем false, если таблица не создана
    }
	return true; // Возвращаем true, если таблица успешно создана
}

bool DataBase::createTableActivities() { // Функция для создания таблицы активностей
	// SQL-запрос для создания таблицы активностей, если она не существует
    const char* sql = R"(
        CREATE TABLE IF NOT EXISTS activities (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL,
            calories_burned_per_minute REAL NOT NULL
        );
    )";
	char* errMsg = nullptr; // Переменная для хранения сообщения об ошибке
	int rc = sqlite3_exec(db, sql, nullptr, nullptr, &errMsg); // Выполняем SQL-запрос
	if (rc != SQLITE_OK) { // Если запрос не выполнен успешно
		cerr << "Ошибка создания таблицы: " << errMsg << "\n"; // Выводим сообщение об ошибке
		sqlite3_free(errMsg); // Освобождаем память, занятую сообщением об ошибке
		return false; // Возвращаем false, если таблица не создана
    }
	return true; // Возвращаем true, если таблица успешно создана
}

bool DataBase::addUser(const User& user) {
	const char* sql = "INSERT INTO users (name, gender, years, growth, weight, activity_type, food_type) VALUES (?, ?, ?, ?, ?, ?, ?);";
	sqlite3_stmt* stmt;

	int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
	if (rc != SQLITE_OK) {
		std::cerr << "Ошибка подготовки запроса: " << sqlite3_errmsg(db) << std::endl;
		return false;
	}

	sqlite3_bind_text(stmt, 1, user.name.c_str(), -1, SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 2, user.gender.c_str(), -1, SQLITE_TRANSIENT);
	sqlite3_bind_double(stmt, 3, user.years);         // years - тип REAL
	sqlite3_bind_double(stmt, 4, user.growth);        // growth - тип REAL
	sqlite3_bind_double(stmt, 5, user.weight);        // weight - тип REAL
	sqlite3_bind_text(stmt, 6, user.activity_type.c_str(), -1, SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 7, user.food_type.c_str(), -1, SQLITE_TRANSIENT);

	rc = sqlite3_step(stmt);
	if (rc != SQLITE_DONE) {
		std::cerr << "Ошибка выполнения запроса: " << sqlite3_errmsg(db) << std::endl;
		sqlite3_finalize(stmt);
		return false;
	}

	sqlite3_finalize(stmt);
	return true;
}

bool DataBase::deleteUser() {
	// SQL-запрос для удаления таблицы пользователей
	const char* sql = "DROP TABLE IF EXISTS users;";
	char* errMsg = nullptr; // Переменная для хранения сообщения об ошибке
	int rc = sqlite3_exec(db, sql, nullptr, nullptr, &errMsg); // Выполняем SQL-запрос
	if (rc != SQLITE_OK) { // Если запрос не выполнен успешно
		cerr << "Ошибка удаления таблицы: " << errMsg << "\n"; // Выводим сообщение об ошибке
		sqlite3_free(errMsg); // Освобождаем память, занятую сообщением об ошибке
		return false; // Возвращаем false, если таблица не удалена
	}
	return true; // Возвращаем true, если таблица успешно удалена
}

bool DataBase::addProduct(const Product& p) { // Функция для добавления продукта в базу данных
	// SQL-запрос для вставки нового продукта в таблицу products с использованием подготовленного выражения
	const char* sql = "INSERT INTO products (name, kcal_per_100g, protein, fat, carbs) VALUES (?, ?, ?, ?, ?);";
	sqlite3_stmt* stmt = nullptr; // Указатель на подготовленный SQL-запрос
	int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr); // Подготавливаем SQL-запрос
	if (rc != SQLITE_OK) { // Если запрос не подготовлен успешно
		cerr << "Ошибка подготовки запроса: " << sqlite3_errmsg(db) << "\n"; // Выводим сообщение об ошибке
		return false; // Возвращаем false, если запрос не подготовлен
	}
	// Привязываем параметры
	sqlite3_bind_text(stmt, 1, p.name.c_str(), -1, SQLITE_TRANSIENT); // Привязываем имя продукта
	sqlite3_bind_double(stmt, 2, p.kcal_per_100g); // Привязываем калории на 100 г
	sqlite3_bind_double(stmt, 3, p.protein); // Привязываем белки
	sqlite3_bind_double(stmt, 4, p.fat); // Привязываем жиры
	sqlite3_bind_double(stmt, 5, p.carbs); // Привязываем углеводы

	rc = sqlite3_step(stmt); // Выполняем подготовленный SQL-запрос
	if (rc != SQLITE_DONE) { // Если запрос не выполнен успешно
		cerr << "Ошибка вставки: " << sqlite3_errmsg(db) << "\n"; // Выводим сообщение об ошибке
		sqlite3_finalize(stmt); // Освобождаем подготовленный запрос
		return false; // Возвращаем false, если продукт не добавлен
	}
	else
		cout << "Продукт успешно добавлен.\n"; // Выводим сообщение об успешном добавлении продукта
	sqlite3_finalize(stmt); // Освобождаем подготовленный запрос
	return true; // Возвращаем true, если продукт успешно добавлен
}

bool DataBase::deleteProductById(int id) { // Функция для удаления продукта по ID
	// SQL-запрос для удаления продукта из таблицы products по ID
    string sql = "DELETE FROM products WHERE id = " + to_string(id) + ";";
	char* errMsg = nullptr; // Переменная для хранения сообщения об ошибке
	int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg); // Выполняем SQL-запрос
	if (rc != SQLITE_OK) { // Если запрос не выполнен успешно
		cerr << "Ошибка удаления: " << errMsg << "\n"; // Выводим сообщение об ошибке
		sqlite3_free(errMsg); // Освобождаем память, занятую сообщением об ошибке
		return false; // Возвращаем false, если продукт не удален
    }
	return true; // Возвращаем true, если продукт успешно удален
} 

bool DataBase::deleteAllProducts() { // Функция для удаления всех продуктов из базы данных
	const char* sql = "DELETE FROM products;"; // SQL-запрос для удаления всех продуктов из таблицы products
	char* errMsg = nullptr; // Переменная для хранения сообщения об ошибке
	int rc = sqlite3_exec(db, sql, nullptr, nullptr, &errMsg); // Выполняем SQL-запрос
	if (rc != SQLITE_OK) { // Если запрос не выполнен успешно
		cerr << "Ошибка при удалении всех продуктов: " << errMsg << "\n"; // Выводим сообщение об ошибке
		sqlite3_free(errMsg); // Освобождаем память, занятую сообщением об ошибке
		return false; // Возвращаем false, если продукты не удалены
    }
	return true; // Возвращаем true, если все продукты успешно удалены
}


vector<Product> DataBase::getAllProducts() { // Функция для получения всех продуктов из базы данных
	vector<Product> result; // Вектор для хранения продуктов

	const char* sql = "SELECT * FROM products;"; // SQL-запрос для получения всех продуктов из таблицы products
	auto callback = [](void* data, int argc, char** argv, char**) -> int { // Функция обратного вызова для обработки результатов запроса
		auto* vec = static_cast<vector<Product>*>(data); // Приводим указатель data к типу vector<Product>*
		int id = stoi(argv[0]); // Считываем ID продукта
		string name = argv[1]; // Считываем название продукта
		double kcal = stod(argv[2]); // Считываем калории на 100 г
		double protein = stod(argv[3]); // Считываем количество белка
		double fat = stod(argv[4]); // Считываем количество жира
		double carbs = stod(argv[5]); // Считываем количество углеводов

		vec->emplace_back(id, name, kcal, protein, fat, carbs); // Добавляем новый продукт в вектор
		return 0; // Возвращаем 0 для продолжения обработки
        };

	char* errMsg = nullptr; // Переменная для хранения сообщения об ошибке
	int rc = sqlite3_exec(db, sql, callback, &result, &errMsg); // Выполняем SQL-запрос с функцией обратного вызова
	if (rc != SQLITE_OK) { // Если запрос не выполнен успешно
		cerr << "Ошибка SELECT: " << errMsg << "\n"; // Выводим сообщение об ошибке
		sqlite3_free(errMsg); // Освобождаем память, занятую сообщением об ошибке
    }

	return result; // Возвращаем вектор с продуктами
}

bool DataBase::addActivities(const Activities& a) {
	// SQL-запрос для вставки новой активности в таблицу activities
	const char* sql = "INSERT INTO activities (name, calories_burned_per_minute) VALUES (?, ?);";
	sqlite3_stmt* stmt = nullptr; // Указатель на подготовленный SQL-запрос
	int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr); // Подготавливаем SQL-запрос
	if (rc != SQLITE_OK) { // Если запрос не подготовлен успешно
		cerr << "Ошибка подготовки запроса: " << sqlite3_errmsg(db) << "\n"; // Выводим сообщение об ошибке
		return false; // Возвращаем false, если запрос не подготовлен
	}
	// Привязываем параметры
	sqlite3_bind_text(stmt, 1, a.name.c_str(), -1, SQLITE_TRANSIENT); // Привязываем имя активности
	sqlite3_bind_double(stmt, 2, a.calories_burned_per_minute); // Привязываем калории, сжигаемые за минуту

	rc = sqlite3_step(stmt); // Выполняем подготовленный SQL-запрос
	if (rc != SQLITE_DONE) { // Если запрос не выполнен успешно
		cerr << "Ошибка вставки: " << sqlite3_errmsg(db) << "\n"; // Выводим сообщение об ошибке
		sqlite3_finalize(stmt); // Освобождаем подготовленный запрос
		return false; // Возвращаем false, если активность не добавлена
	}
	else
		cout << "Активность успешно добавлена.\n"; // Выводим сообщение об успешном добавлении активности
	sqlite3_finalize(stmt); // Освобождаем подготовленный запрос
	return true; // Возвращаем true, если активность успешно добавлена
}

bool DataBase::deleteActivityById(int id) { // Функция для удаления активности по ID
	string sql = "DELETE FROM activities WHERE id = " + to_string(id) + ";"; // SQL-запрос для удаления активности по ID
	char* errMsg = nullptr; // Переменная для хранения сообщения об ошибке
	int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg); // Выполняем SQL-запрос
	if (rc != SQLITE_OK) { // Если запрос не выполнен успешно
		cerr << "Ошибка удаления: " << errMsg << "\n"; // Выводим сообщение об ошибке
		sqlite3_free(errMsg); // Освобождаем память, занятую сообщением об ошибке
		return false; // Возвращаем false, если активность не удалена
	}
	return true; // Возвращаем true, если активность успешно удалена
}

bool DataBase::deleteAllActivities() { // Функция для удаления всех активностей из базы данных
	const char* sql = "DELETE FROM activities;"; // SQL-запрос для удаления всех активностей из таблицы activities
	char* errMsg = nullptr; // Переменная для хранения сообщения об ошибке
	int rc = sqlite3_exec(db, sql, nullptr, nullptr, &errMsg); // Выполняем SQL-запрос
	if (rc != SQLITE_OK) { // Если запрос не выполнен успешно
		cerr << "Ошибка при удалении всех активностей: " << errMsg << "\n"; // Выводим сообщение об ошибке
		sqlite3_free(errMsg); // Освобождаем память, занятую сообщением об ошибке
		return false; // Возвращаем false, если активности не удалены
	}
	return true; // Возвращаем true, если все активности успешно удалены
}

vector<Activities> DataBase::getAllActivities() { // Функция для получения всех активностей из базы данных
	vector<Activities> result; // Вектор для хранения активностей
	const char* sql = "SELECT * FROM activities;"; // SQL-запрос для получения всех активностей из таблицы activities
	auto callback = [](void* data, int argc, char** argv, char**) -> int { // Функция обратного вызова для обработки результатов запроса
		auto* vec = static_cast<vector<Activities>*>(data); // Приводим указатель data к типу vector<Activities>*
		int id = stoi(argv[0]); // Считываем ID активности
		string name = argv[1]; // Считываем название активности
		double calBurn = stod(argv[2]); // Считываем калории, сжигаемые за минуту
		vec->emplace_back(id, name, calBurn); // Добавляем новую активность в вектор
		return 0; // Возвращаем 0 для продолжения обработки
	};
	char* errMsg = nullptr; // Переменная для хранения сообщения об ошибке
	int rc = sqlite3_exec(db, sql, callback, &result, &errMsg); // Выполняем SQL-запрос с функцией обратного вызова
	if (rc != SQLITE_OK) { // Если запрос не выполнен успешно
		cerr << "Ошибка SELECT: " << errMsg << "\n"; // Выводим сообщение об ошибке
		sqlite3_free(errMsg); // Освобождаем память, занятую сообщением об ошибке
	}
	return result; // Возвращаем вектор с активностями
}


