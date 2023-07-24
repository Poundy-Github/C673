from conans import ConanFile, CMake, tools


class PdoToolConan(ConanFile):
    name = "pdo_tool"
    version = "2.17"
    settings = "os"
    options = {"shared": [True, False]}
    default_options = "shared=False"
    generators = "cmake"
    exports_sources = "*"

    def package(self):
        self.copy("*.exe")
        self.copy("*.cfg")
        self.copy("*.pdf")
        self.copy("*.pl")
        self.copy("pdo_launcher/*.py")
        