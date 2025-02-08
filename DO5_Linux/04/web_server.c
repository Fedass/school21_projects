#include "fcgiapp.h"

int main() {
    FCGX_Request request;
    FCGX_Init();
    FCGX_InitRequest(&request, 0, 0);

    while (FCGX_Accept_r(&request) >= 0) {
        FCGX_FPrintF(request.out, "Content-type: text/html\r\n\r\n");
        FCGX_FPrintF(request.out, "<html><body><h1>Hello World!</h1></body></html>");
    }

    return 0;
}