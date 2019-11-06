/*  Manages a mathematical set (aka a bag, no repeats) of integers of a certain size set at creation. 
Adjusts size automatically.
*/

class Ensemble {
    public:
    unsigned int cardAct;
    unsigned int cardMax;
    int *bag;
    const static unsigned int CARD_MAX = 5;

    enum crduEstInclus {
        NON_INCLUSION = 1,
        INCLUSION_LARGE = 2,
        INCLUSION_STRICTE = 3
    };

    enum crduAjouter {
        DEJA_PRESENT = 1,
        PLEIN = 2,
        AJOUTE = 3
    };
    
    Ensemble(unsigned int cardMax = CARD_MAX);
    Ensemble(int arr[], unsigned int nbElements);
    virtual ~Ensemble();
    void Afficher();
    bool EstEgal(const Ensemble & unEnsemble) const;
    crduEstInclus EstInclus() const;
    crduAjouter Ajouter(int aAjouter);
    unsigned int Ajuster(int delta);
    bool Retirer(int element);
    bool Retirer(const Ensemble & unEnsemble);
    int Reunir(const Ensemble & unEnsemble);
    unsigned int Intersection(const Ensemble & unEnsemble);

};

