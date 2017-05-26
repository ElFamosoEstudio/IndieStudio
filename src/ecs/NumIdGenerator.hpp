//
// NumIdGenerator.hpp for IndieStudio in /home/silvy_n/projects/IndieStudio
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Fri May 26 21:58:12 2017 Noam Silvy
// Last update Fri May 26 22:16:24 2017 Noam Silvy
//

#ifndef INDIESTUDIO_IDGENERATOR_HPP
# define INDIESTUDIO_IDGENERATOR_HPP

# include <cstdint>
# include "IIdGenerator.hpp"

template<typename Id = std::uint32_t>
class NumIdGenerator : public IIdGenerator<Id>
{
private:
  Id		_id;
public:
  NumIdGenerator() : _id(1) {}
  ~NumIdGenerator() {}
  NumIdGenerator(NumIdGenerator const &) = delete;
  NumIdGenerator &operator=(NumIdGenerator const &) = delete;

  Id		createId() { return (_id++); }
  void		removeId(Id) {}
};

#endif //INDIESTUDIO_IDGENERATOR_HPP
