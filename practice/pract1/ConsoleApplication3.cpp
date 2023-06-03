#include <iostream>
#include <string>
#include <vector>

class Fibo {
private:
	std::string m_text;
	std::string m_encode_text;
	std::string m_decode_text;

	//std::vector<int> key;
	std::vector<std::string> splitedText;

	const int fibo_nums[30] = { 1, 2, 3, 5, 8, 13, 21, 34, 55, 89,
								144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946,
								17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269 };

	void splitText(const std::string& text) {
		std::string temp;

		for (int i = 0; i < text.size(); i++) {
			if (text[i] == ' ') {
				splitedText.push_back(temp);
				temp.clear();
				continue;
			}
			if (i == text.size() - 1) {
				temp += text[i];
				splitedText.push_back(temp);
			}
			temp += text[i];	
		}
	}

	int fibo_index(int&  num) {
		for (int i = 0; i < 30; i++) {
			if (fibo_nums[i] == num) {
				return i;
			}
		}
	}
public:
	Fibo() = default;
	Fibo(const std::string& text) {
		m_text = text;
	}

	~Fibo(){}

	std::string Encode(std::vector<int>& key) {
		splitText(m_text);
		for (int i : key) {
			m_encode_text += splitedText[fibo_index(i)] + ' ';
		}
		return m_encode_text;
	}

	std::string Decode(std::vector<int>& key){
		splitedText.clear();
		splitText(m_encode_text);

		for (int i : key) {
			m_decode_text += splitedText[fibo_index(i)] + ' ';
		}
		return m_decode_text;
	}
};



int main()
{
	std::string text = "Hello, my name is Ivan.";
	std::vector<int> key{2,8,5,1,3 };

	Fibo str(text);

	std::string s1 = str.Encode(key);
	std::cout << s1 << std::endl;

	std::string s2 = str.Decode(key);

	std::cout << s2 << std::endl;


}



