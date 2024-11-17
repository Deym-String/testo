namespace offset
{

    namespace player
    {
        constexpr uint64_t update = 0x1;  //Need for hook!
        constexpr uint64_t playerAlive = 0x2;  //Ofc we don't render dead players!
        constexpr uint64_t isMine = 0x3; //We also won't render ourself
        constexpr uint64_t playerOnTeam = 0x4; //We will only render enemy
    }
    namespace unityEngine
    {
        namespace transform
        {
            constexpr uint64_t get_position_injected = 0x4; //Aaccesses the position of a transform in the game world
            constexpr uint64_t get_localScale = 0x9; //We'll use this to set the box width / height
        }
        namespace component
        {
            constexpr uint64_t get_transform = 0x5; //Retrieves the transform component of a game objec
        }
    }
    namespace camera
    {
        constexpr uint64_t worldToViewPort_injected = 0x7; //We need to convert the player coordinates to screen
        constexpr uint64_t allCameras = 0x8; //This is a monoArray, this will be used to get the main camera, very important to access worldtoviewport
    }
}