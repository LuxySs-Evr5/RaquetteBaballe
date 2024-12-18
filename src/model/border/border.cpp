#include "border.hpp"

Border::Border(const BoundingBox &boundingBox) : Bounceable(boundingBox) {}

Border::Border(const Border &other) : Bounceable(other) {}

Border::~Border() = default;
