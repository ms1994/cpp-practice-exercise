#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    Solution()
    {

    }
    void Ballons() //Muy mal codigo, se debe mejorar la complexity es de n¨2
                //la mejor solucion es buscar siempre el menor valor y su posicion, simpre y cuando
                // n es mayor a 2. La explicacion es que cuando n es mayor a 2 me aseguro seleccionando
                //un solo paquete con la menor cantidad de globos siempre sera distinto a la otra seleciion
                // Problema para practicar la logica matematica
    {
        int P;
        cin >> P;
        if (P <= 1 || P > 10) cout << -1 << '\n';
        else
        {
            vector <int> gregory;
            vector <int> andrew;
            int contG = 0, contA = 0;
            int a;
            vector <int>packets;
            for (int i = 0; i < P; i++)
            {
                cin >> a;
                packets.push_back(a);
                if (andrew.size() == 0)
                {
                    andrew.push_back(a);
                    contA += a;
                }
                else if (gregory.size() == 0)
                {
                    gregory.push_back(a);
                    contG += a;

                }
                else if (contG + a != contA)
                {
                    gregory.push_back(a);
                    contG += a;
                }
                else {
                    andrew.push_back(a);
                    contA +=a;
                }
            }
            if (contA == contG)
                cout << -1 << '\n';
            else if (contA < contG)
            {
                cout << andrew.size() << '\n';
                for (auto it: andrew)
                {
                    for (size_t i = 0; i < packets.size(); i++)
                        if (it == packets[i])
                        {
                            cout << i + 1 << " ";
                            break;
                        }
                }

            }
            else
            {
                cout << gregory.size() << '\n';
                for (auto it : gregory)
                {
                     for (size_t i = 0; i < packets.size(); i++)
                        if (it == packets[i])  {
                        cout << i + 1 << " ";
                        break;
                    }
                }

            }
        }
    }

};

int main()
{
    Solution obj;
    obj.Ballons();
    return 0;
}
