#include "merchanthoard.h"

const int MERCHANT_HOARD_VAL = 4;

MerchantHoard::MerchantHoard(Player *player)
    : Gold{ "Merchant Hoard", player, nullptr, MERCHANT_HOARD_VAL,false } {}
