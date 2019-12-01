//
// Created by tfian on 25/11/2019.
//

#ifndef RTYPE_EVENTS_HPP
#define RTYPE_EVENTS_HPP

class Events
{
public:
    bool isLeftArrow() const;

    void setLeftArrow(bool leftArrow);

    bool isRightArrow() const;

    void setRightArrow(bool rightArrow);

    bool isUpArrow() const;

    void setUpArrow(bool upArrow);

    bool isDownArrow() const;

    void setDownArrow(bool downArrow);

    bool isAKey() const;

    void setAKey(bool aKey);

    bool isBKey() const;

    void setBKey(bool bKey);

    bool isCKey() const;

    void setCKey(bool cKey);

    bool isDKey() const;

    void setDKey(bool dKey);

    bool isEKey() const;

    void setEKey(bool eKey);

    bool isFKey() const;

    void setFKey(bool fKey);

    bool isGKey() const;

    void setGKey(bool gKey);

    bool isHKey() const;

    void setHKey(bool hKey);

    bool isIKey() const;

    void setIKey(bool iKey);

    bool isJKey() const;

    void setJKey(bool jKey);

    bool isKKey() const;

    void setKKey(bool kKey);

    bool isLKey() const;

    void setLKey(bool lKey);

    bool isMKey() const;

    void setMKey(bool mKey);

    bool isNKey() const;

    void setNKey(bool nKey);

    bool isOKey() const;

    void setOKey(bool oKey);

    bool isPKey() const;

    void setPKey(bool pKey);

    bool isQKey() const;

    void setQKey(bool qKey);

    bool isRKey() const;

    void setRKey(bool rKey);

    bool isSKey() const;

    void setSKey(bool sKey);

    bool isTKey() const;

    void setTKey(bool tKey);

    bool isUKey() const;

    void setUKey(bool uKey);

    bool isVKey() const;

    void setVKey(bool vKey);

    bool isWKey() const;

    void setWKey(bool wKey);

    bool isXKey() const;

    void setXKey(bool xKey);

    bool isYKey() const;

    void setYKey(bool yKey);

    bool isZKey() const;

    void setZKey(bool zKey);

    bool isEnter() const;

    void setEnter(bool enter);

    void resetEvent();

private:
    bool enter = false;

    bool leftArrow = false;
    bool rightArrow = false;
    bool upArrow = false;
    bool downArrow = false;

    bool aKey = false;
    bool bKey = false;
    bool cKey = false;
    bool dKey = false;
    bool eKey = false;
    bool fKey = false;
    bool gKey = false;
    bool hKey = false;
    bool iKey = false;
    bool jKey = false;
    bool kKey = false;
    bool lKey = false;
    bool mKey = false;
    bool nKey = false;
    bool oKey = false;
    bool pKey = false;
    bool qKey = false;
    bool rKey = false;
    bool sKey = false;
    bool tKey = false;
    bool uKey = false;
    bool vKey = false;
    bool wKey = false;
    bool xKey = false;
    bool yKey = false;
    bool zKey = false;
};
#endif //RTYPE_EVENTS_HPP
