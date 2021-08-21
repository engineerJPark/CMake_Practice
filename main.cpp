#include <iostream>
#include <adder.h>
#include <GLFW/glfw3.h>
#include <OLASConfig.h>
using namespace std;
 
 
int main(int argc, char * argv[]){
   cout << "Hello" << '\n';
   cout << add(72.1, 73.8) << '\n';
   
   cout << argv[0] << "-Version" << OLAS_VERSION_MAJOR << "." << OLAS_VERSION_MINOR << '\n';
   
   GLFWwindow *window;
 
   if( !glfwInit() ){
      fprintf(stderr, “Failed to initialize GLFW\n”);
      exit(EXIT_FAILURE);
   }
 
   window = glfwCreateWindow(300,300,”GEARS”,NULL,NULL);
   if( !window ){
      fprintf(stderr, “Failed to open GLFW window\n”);
      exit(EXIT_FAILURE);
   }
 
   while( !glfwWindowShouldClose(window) ){
      // Draw Gears
      draw();
 
      // Update animation
      animate();
 
      // Swap buffers
      glfwSwapBuffers(window);
      glfwPollEvents();
   }
   // Terminate GLFW
   glfwTerminate();
 
   return 0;
}
