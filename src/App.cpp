
#include "controller/MyController.hpp"
#include "AppComponent.hpp"

#include "oatpp/network/Server.hpp"

#include "oatpp/core/macro/codegen.hpp"


void run(void) {
    AppComponent components;

    OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router);

    auto myController = std::make_shared<MyController>();
    router->addController(myController);

    OATPP_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, connectionHandler);
    OATPP_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, connectionProvider);

    oatpp::network::Server server(connectionProvider, connectionHandler);

    OATPP_LOGI("MyAPP", "Server running on port %s", connectionProvider->getProperty("port").getData());

    server.run();
}



int main(int argc, const char* argv[]) {
    oatpp::base::Environment::init();
    run();
    oatpp::base::Environment::destroy();

    return 0;
}