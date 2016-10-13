from conans import ConanFile, GCC

class EdenCraft(ConanFile):
	settings = "os", "compiler", "build_type", "arch"
	requires = ""
	generators = "gcc", "txt"
	options = {"shared": [True, False]}
	default_options = "shared=False"

	def imports(self):
		self.copy("*.a" dst="lib" src="")
		self.copy("*.lib" dst="lib" src="")
