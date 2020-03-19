# Lunar Knights
 
# Sachin Shah
# February 10, 2020

# Build script to create the python api

from distutils.core import setup, Extension

module1 = Extension('lkpy',
					include_dirs = ['include'],
					libraries = ['LunarKnights', 'CTRE_Phoenix', 'CTRE_PhoenixCCI', 'CTRE_PhoenixPlatformLinuxSocketCan', 'CTRE_PhoenixCanutils'],
					library_dirs = ['lib'],
					sources = ['src/lkpymodule.cpp'])

setup (name = 'Lunar Knights Python',
		version = '1.0',
		description = 'Control the robot with python code',
		ext_modules = [module1])
