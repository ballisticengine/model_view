import sys

BALLISTIC_SRC = '../ballistic_engine'
BALLISTIC_SCONS = BALLISTIC_SRC + '/site_scons/'

print(BALLISTIC_SCONS)

sys.path.insert(0, BALLISTIC_SCONS)

from common_flags import *

SRC  = './src/'

BULLET_LIBS = ['BulletCollision', 'BulletSoftBody', 'BulletDynamics', 'LinearMath']
BOOST_LIBS = ['boost_timer', 'boost_filesystem', 'boost_system', 'boost_thread', 'boost_python', ]
SDL_LIBS = ['SDL2', 'SDL2_ttf', 'SDL2_image', ]
GL_LIBS = ['GL', 'GLEW', 'GLU']
GENERAL_LIBS = ['stdc++', 'pthread', 'python2.7', 'dl', ]
TEST_LIBS = ['gtest', 'gtest_main' ]

ALL_LIBS = GENERAL_LIBS + BOOST_LIBS + SDL_LIBS + GL_LIBS + BULLET_LIBS + ROCKET_LIBS

env = Environment(CPPPATH=[
    '/usr/include/python2.7',
    '/usr/include/bullet',
    './src/ui/librocket_interfaces',
    '/usr/local/include/Rocket',
    BALLISTIC_SRC+'/src',
    SRC,
])

modules = [
    Glob(SRC + '/*.cpp'),
]

env.Append(LINKFLAGS=['-rdynamic'])
env.Program('./bin/modelview', modules, LIBS=['engine']+ALL_LIBS, LIBPATH=BALLISTIC_SRC+'/bin', CXXFLAGS=COMMON_CXX_FLAGS )

