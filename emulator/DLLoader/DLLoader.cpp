#include "IGame.hpp"
#include "IGraphic.hpp"
#include "DLLoader.hpp"

template <class T>
DLLoader<T>::DLLoader(std::string const &entryPoint)
{
  _entryPoint = entryPoint;
}

template <class T>
DLLoader<T>::~DLLoader()
{
}

template <class T>
void *DLLoader<T>::getErr(const char *err)
{
  std::cerr << err << std::endl;
  return nullptr;
}

template <class T>
Sptr_t<T> DLLoader<T>::getInstance(std::string const &dynLib)
{
  Sptr_t<T>	(*accessClass)();

  if (!(_handle = dlopen(dynLib.c_str(), RTLD_NOW | RTLD_LAZY))
      || !(accessClass = reinterpret_cast<Sptr_t<T> (*)()>
			 (dlsym(_handle, _entryPoint.c_str())))) {
    getErr(dlerror());
    throw std::exception();
  }
  _dynLib = accessClass();
  return _dynLib;
}

template <class T>
void	*DLLoader<T>::closeInstance()
{
  if (dlclose(_handle) != 0) {
    return (getErr(dlerror()));
  }
  return nullptr;
}

template <class T>
bool DLLoader<T>::isDSOFile(std::string const &path)
{
  size_t	dso;

  dso = path.size();
  if (path.find(".so") == std::string::npos
      || path.find(".so") != dso - 3) {
    return false;
  }
  return true;
}

template class DLLoader<retromania::IGame>;
template class DLLoader<retromania::IGraphic>;
template class DLLoader<void>;

