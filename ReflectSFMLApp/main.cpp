
#include <iostream>

#include "cxx_mirror.h"

int main()
{
    auto getGlobalVolume = cxx::mirror().getFunction(cxx::fn::sf::Listener::getGlobalVolume::id)
                                        ->argsT().returnT();
    auto [err, gvol] = getGlobalVolume();

    if (err != rtl::error::None) {
        std::cout << "Reflection call error : " << rtl::to_string(err);
    }
    else {
        std::cout << "Reflection call successful, volume (returned) : " << gvol.view<float>()->get();
    }

    return 0;
}