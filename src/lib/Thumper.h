#pragma once

#include "restclient-cpp/restclient.h"

namespace touchberry{
    class THUMPER{
      private:
        char buf[];
        RestClient::Response r;

      public:
        THUMPER();
        void Speed(int left, int right);
        void Neo();
        void NeoBlink();
        void Battery();
    };
}
