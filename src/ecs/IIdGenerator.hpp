//
// IIdGenerator.hpp for IndieStudio in /home/silvy_n/projects/IndieStudio
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Fri May 26 19:59:43 2017 Noam Silvy
// Last update Fri May 26 21:58:53 2017 Noam Silvy
//

#ifndef INDIESTUDIO_IIDGENERATOR_HPP
# define INDIESTUDIO_IIDGENERATOR_HPP

template<typename Id>
class IIdGenerator
{
public:
  virtual	~IIdGenerator() {}
  virtual Id	createId() = 0;
  virtual void	removeId(Id) = 0;
};

#endif //INDIESTUDIO_IIDGENERATOR_HPP
