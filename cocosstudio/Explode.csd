<GameProjectFile>
  <PropertyGroup Type="Node" Name="Explode" ID="b387b1b2-a4a5-4ae4-a1ab-28d0d1586116" Version="2.2.8.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="7" Speed="0.1667">
        <Timeline ActionTag="2132910788" Property="FileData">
          <TextureFrame FrameIndex="1" Tween="False">
            <TextureFile Type="Normal" Path="asset/explode1.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="2" Tween="False">
            <TextureFile Type="Normal" Path="asset/explode2.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="3" Tween="False">
            <TextureFile Type="Normal" Path="asset/expload3.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="5" Tween="False">
            <TextureFile Type="Normal" Path="asset/bombExplode1.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="6" Tween="False">
            <TextureFile Type="Normal" Path="asset/bombExplode2.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="7" Tween="False">
            <TextureFile Type="Normal" Path="asset/bombExplode3.png" Plist="" />
          </TextureFrame>
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="BallExplode" StartIndex="1" EndIndex="4">
          <RenderColor A="255" R="205" G="92" B="92" />
        </AnimationInfo>
        <AnimationInfo Name="BombExplode" StartIndex="5" EndIndex="8">
          <RenderColor A="150" R="165" G="42" B="42" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Node" CustomClassName="Explode" Tag="78" ctype="GameNodeObjectData">
        <Size />
        <Children>
          <AbstractNodeData Name="explode1_1" ActionTag="2132910788" Tag="79" Rotation="360.0000" RotationSkewX="360.0000" RotationSkewY="360.0000" IconVisible="False" LeftMargin="-96.7479" RightMargin="-103.2521" TopMargin="-93.2618" BottomMargin="-106.7382" ctype="SpriteObjectData">
            <Size X="200.0000" Y="200.0000" />
            <AnchorPoint ScaleX="0.4810" ScaleY="0.5392" />
            <Position X="-0.5382" Y="1.1071" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize />
            <FileData Type="Normal" Path="asset/bombExplode3.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>