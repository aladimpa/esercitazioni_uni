class Data
{
    public:
            Data();
            Data(int gg, int mm, int aa);
            Data(const Data& data);
            ~Data();
            int getG() const;
            int getM() const;
            int getA() const;
            void setG(int gg);
            void setM(int mm);
            void setA(int aa);
            void inserisci_data();
            void stampa_data();
            void copia_data(Data& data);
    private:
            int _giorno;
            int _mese;
            int _anno;
            int max(int mese, int anno);
};