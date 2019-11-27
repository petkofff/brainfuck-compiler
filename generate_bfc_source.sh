DEVECTOR="R\"##($(cat DEVector.h))##\"" \
DYNAMIC_STRIP="R\"##($(cat DynamicStrip.h))##\"" \
envsubst < bfc.cpp.template > bfc.cpp
