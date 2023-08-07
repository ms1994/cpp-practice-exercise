#include <bits/stdc++.h>


using namespace std;
class Solution
{
vector <vector <int>> allPermutations;
vector <int> permutations;
multiset <int> original;
multiset <int> temp;
int INF = 1E09;
public:
    bool check (int x, vector <vector<int>> matrix, int row, int col)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == x) return true;
            }
        }
        return false;
    }
    void countSubSets()
    {
        int n;
        scanf("%d", &n);
        vector <int> ai(n*n);
        for (auto &x: ai) scanf("%d",&x);
        for (auto a: ai) original.insert(a);
        int matrix[n][n];
        vector <int> row;
        int matrix2[n*n];
        int choose[n];
        int cont = 0;
        memset(choose,0,sizeof(choose));
        int acc = accumulate(ai.begin(), ai.end(), 0);
        int s = acc/n;
        //for (auto it:ai) printf("%d ", it);
        for (int mask=0; mask<=(1 << n*n); mask++)
        {
            if (__builtin_popcount(mask)==n)
            {
                int sum = 0;
                row.clear();
                bool esta = false;
                for (int i=0; i < n*n;i++)
                {
                    if (mask & (1 << i))
                    {
                        if (temp.count(ai[i]) >= original.count(ai[i])) esta = true;
                        sum += ai[i];
                        row.push_back(ai[i]);

                    }
                }
                if (sum == s && !esta)
                {
                    cont++;
                    for (auto a:row) temp.insert(a);
                    generatingPermutations(n,row,choose);
                }
            }
        }
        //int factorial = 1;
       // for (int i = 1; i <= n; i++)
         //   factorial *= i;
       // cout << factorial;
        bool sol2 = false;
        if (cont < n || n == 2)
        {
            //solution check the diagonals
            for (size_t i = 0; i < allPermutations.size(); i++)
            {
                temp.clear();
                memset(matrix2,INF,sizeof(matrix2));
                for (int j = 0; j < n; j++)
                {
                    matrix2[j*(n+1)] = allPermutations[i][j];
                    temp.insert(allPermutations[i][j]);
                }
                sol2 = backstracking2(matrix2,0,n,s,ai);
                if (sol2) break;
            }

        }
        else if (!sol2)
        {
            //solution check the rows
            for (size_t i = 0; i < allPermutations.size(); i++)
            {
                temp.clear();
                memset(matrix2,INF,sizeof(matrix2));
                for (int j = 0; j < n; j++)
                {
                    matrix2[j] = allPermutations[i][j];
                    temp.insert(allPermutations[i][j]);
                }
                sol2 = backstracking2(matrix2,0,n,s,ai);
                if (sol2) break;
            }
        }
        /*temp.clear();
        memset(matrix2,0,sizeof(matrix2));
        bool sol2 = backstracking2(matrix2,0,n,s);
        for (size_t i = 0; i < allPermutations.size(); i++)
        {
            memset(matrix,0,sizeof(matrix));

            bool sol = false;
            bool sol2 = false;
            for (int j = 0; j < n; j++)
            {
                //matrix[j][j] = allPermutations[i][j];
                //matrix2[j*(n+1)] = allPermutations[i][j];
                //temp.insert(allPermutations[i][j]);
            }
            //sol = backstracking((int*) matrix, 0, n, s);

        }*/
       /* for (int i = 0; i<n;i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }*/
        for (int i = 0; i<n;i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d ", matrix2[i*n+j]);
            }
            printf("\n");
        }

    }
    bool checkRow(int row)
    {
        //if (y == i) continue;
        if (temp.count(row) >= original.count(row)) return false;
        return true;
    }
    bool validateAll(int matrix[], int n, int s, int k)
    {
        if (k % n == 0 && k >= n)
        {
            for (int i = 0; i < k/n; i++)
            {
                int sum = 0;
                for (int j = 0; j<n; j++)
                {
                    sum += matrix[(i*n)+j];
                }
                if (sum != s) return false;
            }
        }
        else if (k/n >= n-1)
        {
            for (int i = 0; i <= k-(n*(n-1)); i++)
            {
                int sum = 0;
                for (int j = 0; j < n; j++)
                {
                    sum += matrix[i+(j*n)];;
                }
                if (sum != s) return false;
            }
            int sumS = 0;
            for (int i = 0; i < n; i++)//diagonal secundaria
            {
                sumS += matrix[n-1+(n-1)*i];
            }
            if (sumS != s) return false;
        }
        else
        {
            for (int i = 0; i < k/n; i++)
            {
                int sum = 0;
                for (int j = 0; j<n; j++)
                {
                    sum += matrix[(i*n)+j];
                }
                if (sum > s) return false;
            }
            for (int i = 0; i < n; i++)
            {
                int sum = 0;
                for (int j = 0; j < n; j++)
                {
                    sum += matrix[i+(j*n)];;
                }
                if (sum > s) return false;
            }
            int sumD = 0;
            int sumS = 0;
            for (int i = 0; i < n; i++)//diagonal secundaria
            {
                sumS += matrix[n-1+(n-1)*i];
                sumD += matrix[i*(n+1)];
            }
            if (sumS > s || sumD > s) return false;
        }
        return true;

    }
    bool validateAllExact(int matrix[], int n, int s)
    {
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = 0; j<n; j++)
            {
                sum += matrix[(i*n)+j];
            }
            if (sum != s) return false;
        }
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = 0; j < n; j++)
            {
                sum += matrix[i+(j*n)];;
            }
            if (sum != s) return false;
        }
        int sumD = 0;
        int sumS = 0;
        for (int i = 0; i < n; i++)//diagonal secundaria
        {
            sumS += matrix[n-1+(n-1)*i];
            sumD += matrix[i*(n+1)];
        }
        if (sumS != s || sumD != s) return false;
        return true;
    }
    void generatingPermutations(int n, vector <int> row,int choose[])
    {

        if (permutations.size() == n)
        {
            allPermutations.push_back(permutations);
        }
        else
        {
            for (int i = 0; i<n;i++)
            {
                if (choose[i]) continue;
                choose[i] = 1;
                permutations.push_back(row[i]);
                generatingPermutations(n,row,choose);
                choose[i] = 0;
                permutations.pop_back();
            }
        }
    }
    bool backstracking(int* matrix, int y, int n, int s)
    {
        if (y == n)
        {
            int sumDiag = 0;
            for (int i = 0; i < n; i++)
            {
                int sumCol = 0;
                for (int j = 0; j < n; j++)
                { //row por col y accedo al valor dentro del pointer of pointer
                    sumCol += *(matrix +i*n+j);
                }
                if (sumCol != s) return false;
            }
            for (int i = 0; i < n; i++)//diagonal secundaria
            {
                sumDiag += *(matrix+i*n+(n-1+i));
            }
            return sumDiag != s ? false: true;
        }

        for (size_t i = 0; i < allPermutations.size(); i++)
        {
            if (*(matrix+y*n+y) != allPermutations[i][y]) continue;
            //check if is possible insert the row in the matrix
            //if (!checkRow(allPermutations[i], n, y)) continue;
            for (int j = 0; j < n; j++)
            {
                *(matrix+y*n+j) = allPermutations[i][j];
                temp.insert(allPermutations[i][j]);
            }
            for (int j = 0; j < y; j++)
            {
                for (int k = 0; k<n; k++)
                {
                    cout << *(matrix+y*j+k);
                }
                cout<<endl;
                cout <<"-----" <<endl;
            }
            if (!checkLessSumCol((int*) matrix, n,s)) eraseValues(matrix,y,n,allPermutations[i]);
            if (!checkLessSumDiag((int*)matrix,n,s)) eraseValues(matrix,y,n,allPermutations[i]);
            if (backstracking((int*)matrix, y+1,n,s)) return true;
            else eraseValues(matrix,y,n,allPermutations[i]);
        }
        return false;
    }
    void eraseValues(int* matrix, int y, int n, vector<int> row)
    {
         for (int j = 0; j < n; j++)
            {
                if (j == y) continue;
                *(matrix+y*n+j) = 0;
                temp.erase(row[j]);
            }
    }
    bool checkLessSumCol (int* matrix, int n, int s)
    {
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = 0; j < n; j++)
            {
                sum += *(matrix +i*n+j);
            }
            if (sum > s) return false;
        }
        return true;
    }
    bool checkLessSumDiag (int* matrix, int n, int s)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)//diagonal secundaria
        {
            sum += *(matrix+i*n+(n-1+i));
        }
        return sum > s ? false: true;
    }
    int searchPosition(int matrix[], int n)
    {
        for (int j = 0; j < n*n; j++)
        {
            if (matrix[j] != INF) return j;
        }
        return -1;
    }
    bool checkSumRow(int matrix[], int n, int s)
    {
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = 0; j<n; j++)
            {
                sum += matrix[i*n+j];
            }
            if (sum > s) return false;
        }

        return true;
    }

    bool backstracking2(int matrix[], int y, int n, int s, vector <int> ai)
    {
        int j = searchPosition(matrix,n);
        if (y == n*n || j == -1)
        {
            bool exact = validateAllExact(matrix, n, s);
            return exact ? true :false;
        }

        for (size_t i = 0; i < ai.size(); i++)
        {
            //check if is possible insert the row in the matrix
            if (!checkRow(ai[i])) continue;
            matrix[j] = ai[i];
            temp.insert(ai[i]);
            if (validateAll(matrix,n,s,j))
            {
                if (backstracking2(matrix, y+1,n,s, ai)) return true;
            }//si no es valida lo limpio, si es valida busco otro valor
                //pudieras hacer un solo metodo de validacion de col y diagonal
                //hago una funcion que valide todo
                //si es falso lo limpio al final
            matrix[j] = INF;
            temp.erase(ai[i]);
        }
        return false;
    }
    bool checkLessSumCol2 (int matrix[], int n, int s)
    {
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = 0; j < n; j++)
            {
                sum += matrix[i+(j*n)];;
            }
            if (sum > s) return false;
        }
        return true;
    }
    bool checkLessSumDiag2 (int matrix[], int n, int s)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)//diagonal secundaria
        {
            sum += matrix[n-1+(n-1)*i];
        }
        if (sum > s) return false;
        return true;
    }
};

int main()
{
    Solution obj;
    obj.countSubSets();
    return 0;
}
