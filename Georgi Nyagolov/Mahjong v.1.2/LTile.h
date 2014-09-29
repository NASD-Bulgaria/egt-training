#ifndef LTILE_H
#define LTILE_H

#include <LButton.h>


class LTile : public LButton
{
    public:
        LTile();
        virtual ~LTile();

        bool GetcheckTile();
        void SetcheckTile(bool checking);
        void freeTile();

    protected:
    private:
        bool checkTile;
};

#endif // LTILE_H
