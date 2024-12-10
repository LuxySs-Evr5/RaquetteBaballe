#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "../model/model.hpp"

class Controller {
  private:
    Model model_;

  public:
    virtual void run();
};

#endif
