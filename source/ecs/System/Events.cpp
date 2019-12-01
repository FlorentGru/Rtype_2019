//
// Created by tfian on 25/11/2019.
//

#include "Events.hpp"

bool Events::Events::isLeftArrow() const {
    return leftArrow;
}

void Events::Events::setLeftArrow(bool leftArrow_) {
    this->leftArrow = leftArrow_;
}

bool Events::Events::isRightArrow() const {
    return rightArrow;
}

void Events::Events::setRightArrow(bool rightArrow_) {
    this->rightArrow = rightArrow_;
}

bool Events::Events::isUpArrow() const {
    return upArrow;
}

void Events::Events::setUpArrow(bool upArrow_) {
    this->upArrow = upArrow_;
}

bool Events::Events::isDownArrow() const {
    return downArrow;
}

void Events::Events::setDownArrow(bool downArrow_) {
    this->downArrow = downArrow_;
}

bool Events::Events::isAKey() const {
    return aKey;
}

void Events::Events::setAKey(bool aKey_) {
    this->aKey = aKey_;
}

bool Events::Events::isBKey() const {
    return bKey;
}

void Events::Events::setBKey(bool bKey_) {
    this->bKey = bKey_;
}

bool Events::Events::isCKey() const {
    return cKey;
}

void Events::Events::setCKey(bool cKey_) {
    this->cKey = cKey_;
}

bool Events::isDKey() const {
    return dKey;
}

void Events::setDKey(bool dKey_) {
    this->dKey = dKey_;
}

bool Events::isEKey() const {
    return eKey;
}

void Events::setEKey(bool eKey_) {
    this->eKey = eKey_;
}

bool Events::isFKey() const {
    return fKey;
}

void Events::setFKey(bool fKey_) {
    this->fKey = fKey_;
}

bool Events::isGKey() const {
    return gKey;
}

void Events::setGKey(bool gKey_) {
    this->gKey = gKey_;
}

bool Events::isHKey() const {
    return hKey;
}

void Events::setHKey(bool hKey_) {
    this->hKey = hKey_;
}

bool Events::isIKey() const {
    return iKey;
}

void Events::setIKey(bool iKey_) {
    this->iKey = iKey_;
}

bool Events::isJKey() const {
    return jKey;
}

void Events::setJKey(bool jKey_) {
    this->jKey = jKey_;
}

bool Events::isKKey() const {
    return kKey;
}

void Events::setKKey(bool kKey_) {
    this->kKey = kKey_;
}

bool Events::isLKey() const {
    return lKey;
}

void Events::setLKey(bool lKey_) {
    this->lKey = lKey_;
}

bool Events::isMKey() const {
    return mKey;
}

void Events::setMKey(bool mKey_) {
    this->mKey = mKey_;
}

void Events::setNKey(bool nKey_) {
    this->nKey = nKey_;
}

bool Events::isNKey() const {
    return nKey;
}

bool Events::isOKey() const {
    return oKey;
}

void Events::setOKey(bool oKey_) {
    this->oKey = oKey_;
}

bool Events::isPKey() const {
    return pKey;
}

void Events::setPKey(bool pKey_) {
    this->pKey = pKey_;
}

bool Events::isQKey() const {
    return qKey;
}

void Events::setQKey(bool qKey_) {
    this->qKey = qKey_;
}

bool Events::isRKey() const {
    return rKey;
}

void Events::setRKey(bool rKey_) {
    this->rKey = rKey_;
}

bool Events::isSKey() const {
    return sKey;
}

void Events::setSKey(bool sKey_) {
    this->sKey = sKey_;
}

bool Events::isTKey() const {
    return tKey;
}

void Events::setTKey(bool tKey_) {
    this->tKey = tKey_;
}

bool Events::isUKey() const {
    return uKey;
}

void Events::setUKey(bool uKey_) {
    this->uKey = uKey_;
}

bool Events::isVKey() const {
    return vKey;
}

void Events::setVKey(bool vKey_) {
    this->vKey = vKey_;
}

bool Events::isWKey() const {
    return wKey;
}

void Events::setWKey(bool wKey_) {
    this->wKey = wKey_;
}

bool Events::isXKey() const {
    return xKey;
}

void Events::setXKey(bool xKey_) {
    this->xKey = xKey_;
}

bool Events::isYKey() const {
    return yKey;
}

void Events::setYKey(bool yKey_) {
    this->yKey = yKey_;
}

bool Events::isZKey() const {
    return zKey;
}

void Events::setZKey(bool zKey_) {
    this->zKey = zKey_;
}

bool Events::isEnter() const {
    return enter;
}

void Events::setEnter(bool enter_) {
    this->enter = enter_;
}

void Events::resetEvent()
{
     enter = false;

     leftArrow = false;
     rightArrow = false;
     upArrow = false;
     downArrow = false;

     aKey = false;
     bKey = false;
     cKey = false;
     dKey = false;
     eKey = false;
     fKey = false;
     gKey = false;
     hKey = false;
     iKey = false;
     jKey = false;
     kKey = false;
     lKey = false;
     mKey = false;
     nKey = false;
     oKey = false;
     pKey = false;
     qKey = false;
     rKey = false;
     sKey = false;
     tKey = false;
     uKey = false;
     vKey = false;
     wKey = false;
     xKey = false;
     yKey = false;
     zKey = false;
}

bool Events::thirtyOneConditions()
{
    if (enter) { return false; }

    if (leftArrow) { return false; }
    if (rightArrow) { return false; }
    if (upArrow) { return false; }
    if (downArrow) { return false; }

    if (aKey) { return false; }
    if (bKey) { return false; }
    if (cKey) { return false; }
    if (dKey) { return false; }
    if (eKey) { return false; }
    if (fKey) { return false; }
    if (gKey) { return false; }
    if (hKey) { return false; }
    if (iKey) { return false; }
    if (jKey) { return false; }
    if (kKey) { return false; }
    if (lKey) { return false; }
    if (mKey) { return false; }
    if (nKey) { return false; }
    if (oKey) { return false; }
    if (pKey) { return false; }
    if (qKey) { return false; }
    if (rKey) { return false; }
    if (sKey) { return false; }
    if (tKey) { return false; }
    if (uKey) { return false; }
    if (vKey) { return false; }
    if (wKey) { return false; }
    if (xKey) { return false; }
    if (yKey) { return false; }
    if (zKey) { return false; }
    return true;
}