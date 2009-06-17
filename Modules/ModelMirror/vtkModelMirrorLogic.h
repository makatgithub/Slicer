#ifndef __vtkModelMirrorLogic_h
#define __vtkModelMirrorLogic_h

#include "vtkModelMirrorWin32Header.h"
#include <vtksys/SystemTools.hxx>
#include "vtkObject.h"

#include "vtkSlicerModuleLogic.h"
#include "vtkMRMLScene.h"

#include "vtkModelMirror.h"
#include "vtkMatrix4x4.h"
#include "vtkMRMLModelNode.h"
#include "vtkMRMLLinearTransformNode.h"
#include "vtkMRMLModelMirrorNode.h"

#include <string>
#include <vector>
#include <map>
#include <iterator>



class vtkIntArray;


class VTK_MODELMIRROR_EXPORT vtkModelMirrorLogic : public vtkSlicerModuleLogic
{
  public:
  static vtkModelMirrorLogic *New();
  vtkTypeMacro(vtkModelMirrorLogic,vtkSlicerModuleLogic);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // These methods are used to turn observers on/off when module is entered/exited.
  virtual void Enter ( );
  virtual void Exit ( ) ;
  
  virtual void ProcessMRMLEvents ( vtkObject *caller, unsigned long event,
                                   void *callData );

  // Description:
  // Get/Set MRML node storing parameter values
  vtkGetObjectMacro (ModelMirrorNode, vtkMRMLModelMirrorNode);
  virtual void SetModelMirrorNode( vtkMRMLModelMirrorNode *node )
      {
        vtkSetMRMLNodeMacro ( this->ModelMirrorNode, node );
      }
  
  // Description:
  // Get/Set MRML node storing parameter values
  void SetAndObserveModelMirrorNode(vtkMRMLModelMirrorNode *n) 
      {
      vtkSetAndObserveMRMLNodeMacro( this->ModelMirrorNode, n);
      }

  virtual vtkIntArray* NewObservableEvents();

  vtkGetObjectMacro ( MirrorMatrix, vtkMatrix4x4);
  vtkSetObjectMacro ( MirrorMatrix, vtkMatrix4x4);
  
  vtkGetObjectMacro ( MirrorTransform, vtkMRMLLinearTransformNode );
  vtkSetObjectMacro ( MirrorTransform, vtkMRMLLinearTransformNode );
  
  virtual void CreateMirrorModel ();
  virtual void CreateMirrorTransform ( );
  virtual void CreateMirrorMatrix( );
  virtual int HardenTransform();
  virtual int  FlipNormals();

 protected:
  vtkModelMirrorLogic();
  ~vtkModelMirrorLogic();
  vtkModelMirrorLogic(const vtkModelMirrorLogic&);
  void operator=(const vtkModelMirrorLogic&);

  bool Visited;
  bool Raised;
  vtkMRMLModelMirrorNode *ModelMirrorNode;
  vtkMRMLLinearTransformNode *MirrorTransform;
  vtkMatrix4x4 *MirrorMatrix;
  
};


#endif

