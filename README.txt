Documentation Author: Niko Procopi 2019

This tutorial was designed for Visual Studio 2017 / 2019
If the solution does not compile, retarget the solution
to a different version of the Windows SDK. If you do not
have any version of the Windows SDK, it can be installed
from the Visual Studio Installer Tool

Welcome to the OOP Drawing Tutorial!
Prerequesites: World Matrix

In this tutorial, we create an entity class
to handle everything that is needed to draw each
object (entity) in the world. Everything in the 
world needs its own World matrix, its own VAO and
VBO, its own array of vertices, so we put those
into the Entity class, and we can make multiple
Entity classes to draw multiple things in the world
