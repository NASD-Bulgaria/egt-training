#ifndef STATISTICS_H
#define STATISTICS_H

class Statistics
{
private:
    int wining_hands;
    int lossing_hands;
    int cash_flow;
    int cash_out;
public:
    Statistics(int wining_hands = 0,int lossing_hands=0,int cash_flow=0,int cash_out=0);

    int getWining_hands() const;
    void setWining_hands(int value);
    int getLossing_hands() const;
    void setLossing_hands(int value);
    int getCash_flow() const;
    void setCash_flow(int value);
    int getCash_out() const;
    void setCash_out(int value);
};

#endif // STATISTICS_H
