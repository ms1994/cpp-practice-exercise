#include <cstdio>
using namespace std;

int n, m;
char S[1100];//array

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", S);//leer un string y guradarlo en el array
		for (int j = 0; j < m; j++) //se procesa inmediatamente
			if (S[j] == '.') {
				if ((i + j) & 1)	S[j] = 'W';//par o impar
				else	S[j] = 'B';
			}
		printf("%s\n", S);//como se printea un string usando scanf y printf
	}
}
