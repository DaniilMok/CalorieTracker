#include "DataBase.h" // ��������� ������������� ���� � DataBase.h
#include <iostream> // ��������� ������������� ���� � iostream
#include <vector> // ��������� ������������� ���� � vector ��� ������ � ���������

using namespace std; // ������������ ���� std ��� ��������

DataBase::DataBase(const char* filename) { // ����������� ��������� ��� ����� ���� ������
	if (sqlite3_open(filename, &db)) { // ��������� ���� ������
		cerr << "������ �����������: " << sqlite3_errmsg(db) << "\n"; // ���� �� ������� ������� ���� ������, ������� ��������� �� ������
		db = nullptr; // ������������� ��������� �� ���� ������ � nullptr
    }
}

DataBase::~DataBase() { // ���������� ��������� ���� ������
	if (db) sqlite3_close(db); // ���� ���� ������ �������, ��������� ��
}

bool DataBase::createTableUsers() { // ������� ��� �������� ������� �������������
	// SQL-������ ��� �������� ������� ���������, ���� ��� �� ����������
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
	char* errMsg = nullptr; // ���������� ��� �������� ��������� �� ������
	int rc = sqlite3_exec(db, sql, nullptr, nullptr, &errMsg); // ��������� SQL-������
	if (rc != SQLITE_OK) { // ���� ������ �� �������� �������
		cerr << "������ �������� �������: " << errMsg << "\n"; // ������� ��������� �� ������
		sqlite3_free(errMsg); // ����������� ������, ������� ���������� �� ������
		return false; // ���������� false, ���� ������� �� �������
	}
	return true; // ���������� true, ���� ������� ������� �������
}

int DataBase::isUserExists(int actualCount) {
	const char* sql = R"(
		SELECT COUNT(*) FROM users;
	)";
	sqlite3_stmt* stmt = nullptr; // ��������� �� �������������� SQL-������
	if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
		cerr << "������ ���������� �������: " << sqlite3_errmsg(db) << "\n";
		return -1;
	}
	sqlite3_bind_int(stmt, 1, actualCount);
	if (sqlite3_step(stmt) != SQLITE_ROW) {
		cerr << "������ ���������� �������: " << sqlite3_errmsg(db) << "\n";
		sqlite3_finalize(stmt);
		return -1;
	}
	actualCount = sqlite3_column_int(stmt, 0); // ���������� ��� �������� ���������� �������������
	sqlite3_finalize(stmt); // ����������� �������������� ������
	if (actualCount == 0) { // ���� ���������� ������������� ����� 0
		return actualCount; // ���������� 0, ���� ������������ �� ������
	} 
	else if (actualCount == 1) {
		return actualCount; // ���������� 1, ���� ������������ ������
	}
	else if (actualCount > 1) {
		return actualCount; // ���������� ���������� ��������� �������������
	}
	else {
		return -1; // ���������� -1 � ������ ����������� ������
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
	char* errMsg = nullptr; // ���������� ��� �������� ��������� �� ������
	int rc = sqlite3_exec(db, sql, nullptr, nullptr, &errMsg); // ��������� SQL-������
	if (rc != SQLITE_OK) { // ���� ������ �� �������� �������
		cerr << "������ �������� �������: " << errMsg << "\n"; // ������� ��������� �� ������
		sqlite3_free(errMsg); // ����������� ������, ������� ���������� �� ������
		return false; // ���������� false, ���� ������� �� �������
	}
	return true; // ���������� true, ���� ������� ������� �������
}

bool DataBase::createTableUserActivities() { // ������� ��� �������� ������� ����������� �������������
	// SQL-������ ��� �������� ������� ����������� �������������, ���� ��� �� ����������
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
	char* errMsg = nullptr; // ���������� ��� �������� ��������� �� ������
	int rc = sqlite3_exec(db, sql, nullptr, nullptr, &errMsg); // ��������� SQL-������
	if (rc != SQLITE_OK) { // ���� ������ �� �������� �������
		cerr << "������ �������� �������: " << errMsg << "\n"; // ������� ��������� �� ������
		sqlite3_free(errMsg); // ����������� ������, ������� ���������� �� ������
		return false; // ���������� false, ���� ������� �� �������
	}
	return true; // ���������� true, ���� ������� ������� �������
}

bool DataBase::createTableUserProducts() { // ������� ��� �������� ������� ��������� �������������
	// SQL-������ ��� �������� ������� ��������� �������������, ���� ��� �� ����������
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
	char* errMsg = nullptr; // ���������� ��� �������� ��������� �� ������
	int rc = sqlite3_exec(db, sql, nullptr, nullptr, &errMsg); // ��������� SQL-������
	if (rc != SQLITE_OK) { // ���� ������ �� �������� �������
		cerr << "������ �������� �������: " << errMsg << "\n"; // ������� ��������� �� ������
		sqlite3_free(errMsg); // ����������� ������, ������� ���������� �� ������
		return false; // ���������� false, ���� ������� �� �������
	}
	return true; // ���������� true, ���� ������� ������� �������
}

bool DataBase::createTableProducts() { // ������� ��� �������� ������� ���������
	// SQL-������ ��� �������� ������� ���������, ���� ��� �� ����������
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
	char* errMsg = nullptr; // ���������� ��� �������� ��������� �� ������
	int rc = sqlite3_exec(db, sql, nullptr, nullptr, &errMsg); // ��������� SQL-������
	if (rc != SQLITE_OK) { // ���� ������ �� �������� �������
		cerr << "������ �������� �������: " << errMsg << "\n"; // ������� ��������� �� ������
		sqlite3_free(errMsg); // ����������� ������, ������� ���������� �� ������
		return false; // ���������� false, ���� ������� �� �������
    }
	return true; // ���������� true, ���� ������� ������� �������
}

bool DataBase::createTableActivities() { // ������� ��� �������� ������� �����������
	// SQL-������ ��� �������� ������� �����������, ���� ��� �� ����������
    const char* sql = R"(
        CREATE TABLE IF NOT EXISTS activities (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL,
            calories_burned_per_minute REAL NOT NULL
        );
    )";
	char* errMsg = nullptr; // ���������� ��� �������� ��������� �� ������
	int rc = sqlite3_exec(db, sql, nullptr, nullptr, &errMsg); // ��������� SQL-������
	if (rc != SQLITE_OK) { // ���� ������ �� �������� �������
		cerr << "������ �������� �������: " << errMsg << "\n"; // ������� ��������� �� ������
		sqlite3_free(errMsg); // ����������� ������, ������� ���������� �� ������
		return false; // ���������� false, ���� ������� �� �������
    }
	return true; // ���������� true, ���� ������� ������� �������
}

bool DataBase::addUser(const User& user) {
	const char* sql = "INSERT INTO users (name, gender, years, growth, weight, activity_type, food_type) VALUES (?, ?, ?, ?, ?, ?, ?);";
	sqlite3_stmt* stmt;

	int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
	if (rc != SQLITE_OK) {
		std::cerr << "������ ���������� �������: " << sqlite3_errmsg(db) << std::endl;
		return false;
	}

	sqlite3_bind_text(stmt, 1, user.name.c_str(), -1, SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 2, user.gender.c_str(), -1, SQLITE_TRANSIENT);
	sqlite3_bind_double(stmt, 3, user.years);         // years - ��� REAL
	sqlite3_bind_double(stmt, 4, user.growth);        // growth - ��� REAL
	sqlite3_bind_double(stmt, 5, user.weight);        // weight - ��� REAL
	sqlite3_bind_text(stmt, 6, user.activity_type.c_str(), -1, SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 7, user.food_type.c_str(), -1, SQLITE_TRANSIENT);

	rc = sqlite3_step(stmt);
	if (rc != SQLITE_DONE) {
		std::cerr << "������ ���������� �������: " << sqlite3_errmsg(db) << std::endl;
		sqlite3_finalize(stmt);
		return false;
	}

	sqlite3_finalize(stmt);
	return true;
}

bool DataBase::deleteUser() {
	// SQL-������ ��� �������� ������� �������������
	const char* sql = "DROP TABLE IF EXISTS users;";
	char* errMsg = nullptr; // ���������� ��� �������� ��������� �� ������
	int rc = sqlite3_exec(db, sql, nullptr, nullptr, &errMsg); // ��������� SQL-������
	if (rc != SQLITE_OK) { // ���� ������ �� �������� �������
		cerr << "������ �������� �������: " << errMsg << "\n"; // ������� ��������� �� ������
		sqlite3_free(errMsg); // ����������� ������, ������� ���������� �� ������
		return false; // ���������� false, ���� ������� �� �������
	}
	return true; // ���������� true, ���� ������� ������� �������
}

bool DataBase::addProduct(const Product& p) { // ������� ��� ���������� �������� � ���� ������
	// SQL-������ ��� ������� ������ �������� � ������� products � �������������� ��������������� ���������
	const char* sql = "INSERT INTO products (name, kcal_per_100g, protein, fat, carbs) VALUES (?, ?, ?, ?, ?);";
	sqlite3_stmt* stmt = nullptr; // ��������� �� �������������� SQL-������
	int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr); // �������������� SQL-������
	if (rc != SQLITE_OK) { // ���� ������ �� ����������� �������
		cerr << "������ ���������� �������: " << sqlite3_errmsg(db) << "\n"; // ������� ��������� �� ������
		return false; // ���������� false, ���� ������ �� �����������
	}
	// ����������� ���������
	sqlite3_bind_text(stmt, 1, p.name.c_str(), -1, SQLITE_TRANSIENT); // ����������� ��� ��������
	sqlite3_bind_double(stmt, 2, p.kcal_per_100g); // ����������� ������� �� 100 �
	sqlite3_bind_double(stmt, 3, p.protein); // ����������� �����
	sqlite3_bind_double(stmt, 4, p.fat); // ����������� ����
	sqlite3_bind_double(stmt, 5, p.carbs); // ����������� ��������

	rc = sqlite3_step(stmt); // ��������� �������������� SQL-������
	if (rc != SQLITE_DONE) { // ���� ������ �� �������� �������
		cerr << "������ �������: " << sqlite3_errmsg(db) << "\n"; // ������� ��������� �� ������
		sqlite3_finalize(stmt); // ����������� �������������� ������
		return false; // ���������� false, ���� ������� �� ��������
	}
	else
		cout << "������� ������� ��������.\n"; // ������� ��������� �� �������� ���������� ��������
	sqlite3_finalize(stmt); // ����������� �������������� ������
	return true; // ���������� true, ���� ������� ������� ��������
}

bool DataBase::deleteProductById(int id) { // ������� ��� �������� �������� �� ID
	// SQL-������ ��� �������� �������� �� ������� products �� ID
    string sql = "DELETE FROM products WHERE id = " + to_string(id) + ";";
	char* errMsg = nullptr; // ���������� ��� �������� ��������� �� ������
	int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg); // ��������� SQL-������
	if (rc != SQLITE_OK) { // ���� ������ �� �������� �������
		cerr << "������ ��������: " << errMsg << "\n"; // ������� ��������� �� ������
		sqlite3_free(errMsg); // ����������� ������, ������� ���������� �� ������
		return false; // ���������� false, ���� ������� �� ������
    }
	return true; // ���������� true, ���� ������� ������� ������
} 

bool DataBase::deleteAllProducts() { // ������� ��� �������� ���� ��������� �� ���� ������
	const char* sql = "DELETE FROM products;"; // SQL-������ ��� �������� ���� ��������� �� ������� products
	char* errMsg = nullptr; // ���������� ��� �������� ��������� �� ������
	int rc = sqlite3_exec(db, sql, nullptr, nullptr, &errMsg); // ��������� SQL-������
	if (rc != SQLITE_OK) { // ���� ������ �� �������� �������
		cerr << "������ ��� �������� ���� ���������: " << errMsg << "\n"; // ������� ��������� �� ������
		sqlite3_free(errMsg); // ����������� ������, ������� ���������� �� ������
		return false; // ���������� false, ���� �������� �� �������
    }
	return true; // ���������� true, ���� ��� �������� ������� �������
}


vector<Product> DataBase::getAllProducts() { // ������� ��� ��������� ���� ��������� �� ���� ������
	vector<Product> result; // ������ ��� �������� ���������

	const char* sql = "SELECT * FROM products;"; // SQL-������ ��� ��������� ���� ��������� �� ������� products
	auto callback = [](void* data, int argc, char** argv, char**) -> int { // ������� ��������� ������ ��� ��������� ����������� �������
		auto* vec = static_cast<vector<Product>*>(data); // �������� ��������� data � ���� vector<Product>*
		int id = stoi(argv[0]); // ��������� ID ��������
		string name = argv[1]; // ��������� �������� ��������
		double kcal = stod(argv[2]); // ��������� ������� �� 100 �
		double protein = stod(argv[3]); // ��������� ���������� �����
		double fat = stod(argv[4]); // ��������� ���������� ����
		double carbs = stod(argv[5]); // ��������� ���������� ���������

		vec->emplace_back(id, name, kcal, protein, fat, carbs); // ��������� ����� ������� � ������
		return 0; // ���������� 0 ��� ����������� ���������
        };

	char* errMsg = nullptr; // ���������� ��� �������� ��������� �� ������
	int rc = sqlite3_exec(db, sql, callback, &result, &errMsg); // ��������� SQL-������ � �������� ��������� ������
	if (rc != SQLITE_OK) { // ���� ������ �� �������� �������
		cerr << "������ SELECT: " << errMsg << "\n"; // ������� ��������� �� ������
		sqlite3_free(errMsg); // ����������� ������, ������� ���������� �� ������
    }

	return result; // ���������� ������ � ����������
}

bool DataBase::addActivities(const Activities& a) {
	// SQL-������ ��� ������� ����� ���������� � ������� activities
	const char* sql = "INSERT INTO activities (name, calories_burned_per_minute) VALUES (?, ?);";
	sqlite3_stmt* stmt = nullptr; // ��������� �� �������������� SQL-������
	int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr); // �������������� SQL-������
	if (rc != SQLITE_OK) { // ���� ������ �� ����������� �������
		cerr << "������ ���������� �������: " << sqlite3_errmsg(db) << "\n"; // ������� ��������� �� ������
		return false; // ���������� false, ���� ������ �� �����������
	}
	// ����������� ���������
	sqlite3_bind_text(stmt, 1, a.name.c_str(), -1, SQLITE_TRANSIENT); // ����������� ��� ����������
	sqlite3_bind_double(stmt, 2, a.calories_burned_per_minute); // ����������� �������, ��������� �� ������

	rc = sqlite3_step(stmt); // ��������� �������������� SQL-������
	if (rc != SQLITE_DONE) { // ���� ������ �� �������� �������
		cerr << "������ �������: " << sqlite3_errmsg(db) << "\n"; // ������� ��������� �� ������
		sqlite3_finalize(stmt); // ����������� �������������� ������
		return false; // ���������� false, ���� ���������� �� ���������
	}
	else
		cout << "���������� ������� ���������.\n"; // ������� ��������� �� �������� ���������� ����������
	sqlite3_finalize(stmt); // ����������� �������������� ������
	return true; // ���������� true, ���� ���������� ������� ���������
}

bool DataBase::deleteActivityById(int id) { // ������� ��� �������� ���������� �� ID
	string sql = "DELETE FROM activities WHERE id = " + to_string(id) + ";"; // SQL-������ ��� �������� ���������� �� ID
	char* errMsg = nullptr; // ���������� ��� �������� ��������� �� ������
	int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg); // ��������� SQL-������
	if (rc != SQLITE_OK) { // ���� ������ �� �������� �������
		cerr << "������ ��������: " << errMsg << "\n"; // ������� ��������� �� ������
		sqlite3_free(errMsg); // ����������� ������, ������� ���������� �� ������
		return false; // ���������� false, ���� ���������� �� �������
	}
	return true; // ���������� true, ���� ���������� ������� �������
}

bool DataBase::deleteAllActivities() { // ������� ��� �������� ���� ����������� �� ���� ������
	const char* sql = "DELETE FROM activities;"; // SQL-������ ��� �������� ���� ����������� �� ������� activities
	char* errMsg = nullptr; // ���������� ��� �������� ��������� �� ������
	int rc = sqlite3_exec(db, sql, nullptr, nullptr, &errMsg); // ��������� SQL-������
	if (rc != SQLITE_OK) { // ���� ������ �� �������� �������
		cerr << "������ ��� �������� ���� �����������: " << errMsg << "\n"; // ������� ��������� �� ������
		sqlite3_free(errMsg); // ����������� ������, ������� ���������� �� ������
		return false; // ���������� false, ���� ���������� �� �������
	}
	return true; // ���������� true, ���� ��� ���������� ������� �������
}

vector<Activities> DataBase::getAllActivities() { // ������� ��� ��������� ���� ����������� �� ���� ������
	vector<Activities> result; // ������ ��� �������� �����������
	const char* sql = "SELECT * FROM activities;"; // SQL-������ ��� ��������� ���� ����������� �� ������� activities
	auto callback = [](void* data, int argc, char** argv, char**) -> int { // ������� ��������� ������ ��� ��������� ����������� �������
		auto* vec = static_cast<vector<Activities>*>(data); // �������� ��������� data � ���� vector<Activities>*
		int id = stoi(argv[0]); // ��������� ID ����������
		string name = argv[1]; // ��������� �������� ����������
		double calBurn = stod(argv[2]); // ��������� �������, ��������� �� ������
		vec->emplace_back(id, name, calBurn); // ��������� ����� ���������� � ������
		return 0; // ���������� 0 ��� ����������� ���������
	};
	char* errMsg = nullptr; // ���������� ��� �������� ��������� �� ������
	int rc = sqlite3_exec(db, sql, callback, &result, &errMsg); // ��������� SQL-������ � �������� ��������� ������
	if (rc != SQLITE_OK) { // ���� ������ �� �������� �������
		cerr << "������ SELECT: " << errMsg << "\n"; // ������� ��������� �� ������
		sqlite3_free(errMsg); // ����������� ������, ������� ���������� �� ������
	}
	return result; // ���������� ������ � ������������
}


