#pragma once
#include <EtFramework/ECS/ComponentView.h>
#include <EtFramework/ECS/EcsController.h>

#include <EtFramework/Components/CameraComponent.h>
#include <EtFramework/Components/TransformComponent.h>



// forward
namespace et { namespace render {
	class Camera;
} }


namespace et {
namespace edit {


//---------------------------
// EditorCameraComponent
//
// describes the state of editor camera behavior
//
struct EditorCameraComponent final
{
	ECS_DECLARE_COMPONENT

public:
	// set by editor
	bool isEnabled = false;

	// inherent
	vec3 movement;

	float speedMultiplier = 1.f;

	float totalPitch = 0.f;
	float totalYaw = 0.f;
};

//---------------------------
// EditorCameraSystemView
//
// ECS access pattern for editor camera behavior
//
struct EditorCameraSystemView final : public fw::ComponentView
{
	EditorCameraSystemView() : fw::ComponentView()
	{
		Declare(camera);
		Declare(transform);
		Declare(baseCamera);
	}

	WriteAccess<EditorCameraComponent> camera;
	WriteAccess<fw::TransformComponent> transform;
	ReadAccess<fw::CameraComponent> baseCamera;
};

//---------------------------
// EditorCameraSystem
//
// Allow the user to move around in the 3D world with keyboard and mouse
//
class EditorCameraSystem final : public fw::System<EditorCameraSystem, EditorCameraSystemView>
{
	static float const s_MoveSpeed;
	static float const s_Accelleration;
	static float const s_RotationSpeed;

public:
	EditorCameraSystem();

	void Process(fw::ComponentRange<EditorCameraSystemView>& ramge) override;
};


} // namespace edit
} // namespace et
