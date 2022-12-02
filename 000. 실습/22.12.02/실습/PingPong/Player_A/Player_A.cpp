#include "../PingPongTableDll/PingPongTable.h"

typedef PingPongTable* (*pCreatePingPongTable)();
typedef void (*pSetWhoAttacked)(PingPongTable* table, char player_name);
typedef void (*pSetAttackSuccess)(PingPongTable* table, bool is_success);
typedef void (*pSetScore)(PingPongTable* table, std::string player, int score);
typedef char (*pGetWhoAttacked)(PingPongTable* table);
typedef bool (*pGetAttackSuccess)(PingPongTable* table);
typedef int (*pGetScore)(PingPongTable* table, std::string player);

int main()
{
    std::string path(PINGPONGTABLE_DLL);
    path = "../lib/" + path;
    HMODULE _dll = ::LoadLibraryA(path.c_str());

    if (_dll != NULL)
    {
        pCreatePingPongTable cpt = (pCreatePingPongTable)GetProcAddress(_dll, "CreatePingPongTable");
        pSetWhoAttacked setWhoAtk = (pSetWhoAttacked)GetProcAddress(_dll, "SetWhoAttacked");
        pSetAttackSuccess setAtkSucc = (pSetAttackSuccess)GetProcAddress(_dll, "SetAttackSuccess");
        pSetScore setScore = (pSetScore)GetProcAddress(_dll, "SetScore");
        pGetWhoAttacked getWhoAtk = (pGetWhoAttacked)GetProcAddress(_dll, "GetWhoAttacked");
        pGetAttackSuccess getAtkSucc = (pGetAttackSuccess)GetProcAddress(_dll, "GetAttackSuccess");
        pGetScore getScore = (pGetScore)GetProcAddress(_dll, "GetScore");

        PingPongTable* t = cpt();
        std::cout << "A�� ����" << std::endl;
        setWhoAtk(t, 'A');
        while (1) {
            char who = getWhoAtk(t);

            if (who == 'B') {
                std::cout << "B�� ������ Ȯ��" << std::endl;
                setWhoAtk(t, 'A');
                setAtkSucc(t, true);
                std::cout << "A�� ����" << std::endl;
            }
            else {
                std::cout << "B�� ������ ���" << std::endl;

                continue;
            }
            

        }
    }

    return 0;
}