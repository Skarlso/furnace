#include <Commander/CommandRegistry.hpp>
#include <aws/core/Aws.h>
#include "commands/CreateCommand.hpp"

int main(int argc, const char *argv[])
{
    Aws::SDKOptions options;
    Aws::InitAPI(options);
    Commander::CommandRegistry* registry = new Commander::CommandRegistry(argc, argv);
    registry->Register(&(Commands::NewCreateCommand));
    registry->Dump();
    registry->Execute();
    Aws::ShutdownAPI(options);
    return 0;
}
