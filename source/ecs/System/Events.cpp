//
// Created by tfian on 25/11/2019.
//

#include "Events.hpp"

bool Events::Events::isLeftArrow() const {
    return leftArrow;
}

void Events::Events::setLeftArrow(bool leftArrow_) {
    Events::leftArrow = leftArrow_;
}

bool Events::Events::isRightArrow() const {
    return rightArrow;
}

void Events::Events::setRightArrow(bool rightArrow_) {
    Events::rightArrow = rightArrow_;
}

bool Events::Events::isUpArrow() const {
    return upArrow;
}

void Events::Events::setUpArrow(bool upArrow_) {
    Events::upArrow = upArrow_;
}

bool Events::Events::isDownArrow() const {
    return downArrow;
}

void Events::Events::setDownArrow(bool downArrow_) {
    Events::downArrow = downArrow_;
}

bool Events::Events::isAKey() const {
    return aKey;
}

void Events::Events::setAKey(bool aKey_) {
    Events::aKey = aKey_;
}

bool Events::Events::isBKey() const {
    return bKey;
}

void Events::Events::setBKey(bool bKey_) {
    Events::bKey = bKey_;
}

bool Events::Events::isCKey() const {
    return cKey;
}

void Events::Events::setCKey(bool cKey_) {
    Events::cKey = cKey_;
}

bool Events::isDKey() const {
    return dKey;
}

void Events::setDKey(bool dKey_) {
    Events::dKey = dKey_;
}

bool Events::isEKey() const {
    return eKey;
}

void Events::setEKey(bool eKey_) {
    Events::eKey = eKey_;
}

bool Events::isFKey() const {
    return fKey;
}

void Events::setFKey(bool fKey_) {
    Events::fKey = fKey_;
}

bool Events::isGKey() const {
    return gKey;
}

void Events::setGKey(bool gKey_) {
    Events::gKey = gKey_;
}

bool Events::isHKey() const {
    return hKey;
}

void Events::setHKey(bool hKey_) {
    Events::hKey = hKey_;
}

bool Events::isIKey() const {
    return iKey;
}

void Events::setIKey(bool iKey_) {
    Events::iKey = iKey_;
}

bool Events::isJKey() const {
    return jKey;
}

void Events::setJKey(bool jKey_) {
    Events::jKey = jKey_;
}

bool Events::isKKey() const {
    return kKey;
}

void Events::setKKey(bool kKey_) {
    Events::kKey = kKey_;
}

bool Events::isLKey() const {
    return lKey;
}

void Events::setLKey(bool lKey_) {
    Events::lKey = lKey_;
}

bool Events::isMKey() const {
    return mKey;
}

void Events::setMKey(bool mKey_) {
    Events::mKey = mKey_;
}

void Events::setNKey(bool nKey) {
    Events::nKey = nKey;
}

bool Events::isNKey() const {
    return nKey;
}

bool Events::isOKey() const {
    return oKey;
}

void Events::setOKey(bool oKey_) {
    Events::oKey = oKey_;
}

bool Events::isPKey() const {
    return pKey;
}

void Events::setPKey(bool pKey_) {
    Events::pKey = pKey_;
}

bool Events::isQKey() const {
    return qKey;
}

void Events::setQKey(bool qKey_) {
    Events::qKey = qKey_;
}

bool Events::isRKey() const {
    return rKey;
}

void Events::setRKey(bool rKey_) {
    Events::rKey = rKey_;
}

bool Events::isSKey() const {
    return sKey;
}

void Events::setSKey(bool sKey_) {
    Events::sKey = sKey_;
}

bool Events::isTKey() const {
    return tKey;
}

void Events::setTKey(bool tKey_) {
    Events::tKey = tKey_;
}

bool Events::isUKey() const {
    return uKey;
}

void Events::setUKey(bool uKey_) {
    Events::uKey = uKey_;
}

bool Events::isVKey() const {
    return vKey;
}

void Events::setVKey(bool vKey_) {
    Events::vKey = vKey_;
}

bool Events::isWKey() const {
    return wKey;
}

void Events::setWKey(bool wKey_) {
    Events::wKey = wKey_;
}

bool Events::isXKey() const {
    return xKey;
}

void Events::setXKey(bool xKey_) {
    Events::xKey = xKey_;
}

bool Events::isYKey() const {
    return yKey;
}

void Events::setYKey(bool yKey_) {
    Events::yKey = yKey_;
}

bool Events::isZKey() const {
    return zKey;
}

void Events::setZKey(bool zKey_) {
    Events::zKey = zKey_;
}

bool Events::isEnter() const {
    return enter;
}

void Events::setEnter(bool enter_) {
    Events::enter = enter_;
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