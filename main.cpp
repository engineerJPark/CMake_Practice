#include <iostream>
#include <GLFW/glfw3.h>
#include <OLASConfig.h>
#ifdef USE_ADDER
   #include <adder.h>
#endif

using namespace std;
 
 
int main(int argc, char * argv[]){
   cout << "Hello" << '\n';

   #ifdef USE_ADDER
      cout << "adder.h is included..." << add(72.1, 73.8) << '\n';
   #else
      cout << "adder.h is not included..." << 72.1f + 73.8f << '\n';
   #endif
   cout << argv[0] << "-Version" << OLAS_VERSION_MAJOR << "." << OLAS_VERSION_MINOR << '\n';
   
   // GLFWwindow *window;
 
   //  if( !glfwInit() )
   //  {
   //      fprintf( stderr, "Failed to initialize GLFW\n" );
   //      exit( EXIT_FAILURE );
   //  }

   // window = glfwCreateWindow( 300, 300, "Gears", NULL, NULL );
   //  if (!window)
   //  {
   //      fprintf( stderr, "Failed to open GLFW window\n" );
   //      glfwTerminate();
   //      exit( EXIT_FAILURE );
   //  }

   //      // Main loop
   //  while( !glfwWindowShouldClose(window) )
   //  {
   //      // Swap buffers
   //      glfwSwapBuffers(window);
   //      glfwPollEvents();
   //  }

   //  // Terminate GLFW
   //  glfwTerminate();
 
   return 0;
}
