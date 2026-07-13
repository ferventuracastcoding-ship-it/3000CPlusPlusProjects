#include <clang/Tooling/Tooling.h>
#include <clang/Frontend/FrontendActions.h>

using namespace clang;
using namespace clang::tooling;

int main(int argc,char** argv)
{
    return runToolOnCode(
        std::make_unique<SyntaxOnlyAction>(),
        R"(

            int main()
            {
                int x=5;
                return x;
            }

        )"
    );
}
