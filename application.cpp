#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void url_select(vector<string>url_list) {
	int input_number;

	cout << "表示するURLの番号を入力してください" << endl;
	cout << "番号: ";
	cin >> input_number;

	if (0 < input_number && input_number <= size(url_list)) {
		system(("start chrome.exe " + url_list[input_number - 1]).c_str());
	}
	else {
		cout << "入力された番号は無効です" << endl;
	}
}

int main() {
	ifstream text_file("website_list.txt");
	int i = 0;
	string url;
	vector<string> url_list;

	// URLリストを表示
	if (text_file.is_open()) {
		cout << "URLリスト" << endl;
		while (getline(text_file, url)) {
			// 先頭が「http://」か「https://」の文字列をurl_list配列に代入
			if (url.substr(0, 7) == "http://" || url.substr(0, 8) == "https://") {
				url_list.emplace_back(url);
				cout << "【" << i + 1 << "】" << url_list[i] << endl;
				i++;
			}
		}

		// url_list配列の要素数を判定
		if (url_list.size() == 0) {
			cout << "URLが存在しません" << endl;
		}
		else {
			// 表示するウェブサイトのURL番号の選択
			url_select(url_list);
		}
		text_file.close();
	}
	else {
		cout << "ファイルが存在しません" << endl;
	}
	return 0;
}