#include "DataBase.h" // ��������� ������������� ���� � DataBase.h
#include <iostream> // ��������� ������������� ���� � iostream

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
