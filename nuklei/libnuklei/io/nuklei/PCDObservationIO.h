// (C) Copyright Renaud Detry   2007-2011.
// Distributed under the GNU General Public License. (See accompanying file
// LICENSE.txt or copy at http://www.gnu.org/copyleft/gpl.html)

/** @file */

#ifndef NUKLEI_PCDOBSERVATIONSERIAL_H
#define NUKLEI_PCDOBSERVATIONSERIAL_H


#include <nuklei/Definitions.h>
#include <nuklei/ObservationIO.h>
#include <nuklei/PCDObservation.h>
#include <nuklei/SerializedKernelObservationIO.h>


namespace nuklei {


  class PCDReader : public KernelReader
    {
    public:
      PCDReader(const std::string &observationFileName);
      ~PCDReader();
  
      Observation::Type type() const { return Observation::PCD; }
    protected:
      void init_();
      std::auto_ptr<Observation> readObservation_();
    };

  class PCDWriter : public KernelWriter
  {
  public:
    PCDWriter(const std::string &observationFileName);
    ~PCDWriter();
    
    Observation::Type type() const { return Observation::PCD; }
    
    std::auto_ptr<Observation> templateObservation() const
    { return std::auto_ptr<Observation>(new PCDObservation); }

    void writeBuffer();

  };
  
}

#endif

