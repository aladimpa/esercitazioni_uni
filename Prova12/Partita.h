#include "Data.h"
class Partita
{
    public:
            Partita();
            Partita(Data data, char squadra1[], char squadra2[], int ngoal1, int ngoal2, int nes, int nam);
            Partita(const Partita& p);
            ~Partita();
            Data getData() const;
            const char* getSquadra(int n) const;
            int getNgoal(int n) const;
            int getNespulsi() const;
            int getNammoniti() const;
            void setData(Data data);
            void setSquadra(char squadra1[], char squadra2[]);
            void setNgoal(int n1, int n2);
            void setNespulsi(int espulsi);
            void setNammoniti(int ammoniti);
            void inserisci_partita();
            void stampa_partita();
            void copia_partita(Partita& partita);
    private:
            Data _data;
            char* _squadra[2];
            int _ngoal[2];
            int _nespulsi;
            int _nammoniti;
};