//���̸� �ִ��
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, answer;
vector<int> numbers;
vector<int> temp;
bool visited[9];
int maxValue;

//�κ��� ���
int Calculate() {
	int diffSum = 0;

	for (int i = 0; i < temp.size() - 1; i++) {
		diffSum += abs(temp[i + 1] - temp[i]);
	}
	return diffSum;
}

//���� ���ϱ�
void DFS(int cnt) {
	if (cnt == N) {
		maxValue = max(maxValue, Calculate());
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			temp.push_back(numbers[i]);
			visited[i] = true;

			DFS(cnt + 1);

			//�ʱ�ȭ
			visited[i] = false;
			temp.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int number;
		cin >> number;
		numbers.push_back(number);
	}

	DFS(0);

	cout << maxValue << "\n";
}