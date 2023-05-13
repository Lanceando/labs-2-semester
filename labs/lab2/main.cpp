#include <iostream>
#include <cstring>
#include <string>

class String {
private:
	size_t m_size;
	char* m_str;

public:
	String() = default;

	String(const String& other) {
		m_size = other.m_size;
		m_str = new char[m_size + 1];
		strcpy_s(m_str, m_size + 1, other.m_str);
	}

	String& operator=(const String& other) {
		delete[] m_str;
		m_size = other.m_size;
		m_str = new char[m_size + 1];
		strcpy_s(m_str, m_size + 1, other.m_str);
		return *this;
	}

	~String() {
		delete[] m_str;
	}

	String operator+(const String& other) const {
		String result;
		result.m_size = m_size + other.m_size;
		result.m_str = new char[result.m_size + 1];
		strcpy_s(result.m_str, m_size, m_str);
		strcat_s(result.m_str, other.m_size + 1, other.m_str);
		return result;
	}

	String& operator +=(const String& other) {
		char* temp = new char[m_size + other.m_size + 1];
		strcpy_s(temp, m_size + 1, m_str);
		strcat_s(temp, other.m_size + 1, other.m_str);
		delete[] m_str;
		m_str = temp;
		m_size = m_size + other.m_size;
		return *this;
	}

	char& operator[](size_t i) {
		return m_str[i];
	}

	bool operator < (const String& other) {
		return std::strcmp(m_str, other.m_str) < 0;
	}
	// strcmp сравнивает две строки, если первая строка меньше второй, то функция возращает число меньше нуля

	bool operator > (const String& other) {
		return std::strcmp(m_str, other.m_str) > 0;
	}

	bool operator == (const String& other) {
		return std::strcmp(m_str, other.m_str) == 0;
	}

	friend std::ostream& operator<<(std::ostream& os, const String& str) {
		os << str.m_str;
		return os;
	}

	friend std::istream& operator>>(std::istream& is, String& str) {
		const int max_size = 256;
		char buffer[max_size];
		if (is.getline(buffer, max_size)) {
			str.m_size = std::strlen(buffer);
			str.m_str = new char[str.m_size + 1];
			strcpy_s(str.m_str, str.m_size + 1, buffer);
		}
		return is;
	}


	int find(char a) {
		for (int i = 0; i < m_size; i++) {
			if (m_str[i] == a)
				return i;
		}
		return -1; // символ не найден
	}
	size_t length() const {
		return m_size;
	}

	char* c_str() const {
		return m_str;
	}

	char& at(int i) {
		if ((i >= 0) && (i < m_size))
			return m_str[i];
	}
};


int main()
{
	String s1;
	String s2;
	//String s3;

	std::cin >> s1;

	std::cin >> s2;

	//std::cout << s1 << std::endl;
	//std::cout << s2 << std::endl;
	//s3 = s1 + s2;
	//std::cout << s3 << std::endl;

	s1 += s2;
	std::cout << s1 << std::endl;
	s1.at(0) = 'G';
	std::cout << s1 << std::endl;
}
