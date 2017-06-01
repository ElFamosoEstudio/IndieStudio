/*
** Uncopyable.h for IndieStudio in /home/silvy_n/projects/IndieStudio/src
**
** Made by Noam Silvy
** Login   <silvy_n@epitech.net>
**
** Started on  Wed May 31 18:41:03 2017 Noam Silvy
// Last update Wed May 31 19:07:19 2017 Noam Silvy
*/

class Uncopyable
{
 protected:
  Uncopyable() = default;
  ~Uncopyable() = default;

 public:
  Uncopyable(Uncopyable const&) = delete;
  Uncopyable& operator=(Uncopyable const&) = delete;
};
