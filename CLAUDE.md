# CLAUDE.md

This file guides Claude Code when working in this repository.

## What this repo is

This is a learning project, not a production deliverable. I am learning ROS2
from scratch using an SO101 robot arm as the hardware target, alongside a
Coursera "ROS2 from Scratch" course. The end goal is a portfolio repo that
shows real understanding, not a working demo I can't explain.

I am a beginner ROS2 programmer. I have prior experience with Python and
have trained OpenVLA on this same SO101 arm for pick-and-place tasks in a
research lab, so I'm not new to robotics or ML, just new to ROS2 specifically.

ROS2 distro: Lyrical Luth (released May 2026, LTS). Flag any instructions,
packages, or advice that predate this release and may not be verified
against it.

## Repo structure

- `reference/` — the original cloned `msf4-0/so101_ros2` package. Read-only.
  This shows how the hardware bridge works. Never copy code from here into
  my own packages.
- `ros2_ws/src/so101_bringup/` — my launch files.
- `ros2_ws/src/so101_learning/` — my own nodes, written as I learn each
  ROS2 concept.
- `ros2_ws/src/so101_msgs/` — my own custom message/service definitions.
- `notes/` — one markdown file per ROS2 concept (nodes, topics, services,
  actions, URDF, etc). I fill these in myself as I learn.
- `docs/` — screenshots, rqt_graph exports, demo clips.

## How to help me: the core rule

**Do not write finished node logic for me and hand it over.** If I ask you
to "add a publisher node" or similar, don't just generate the file. Instead:

1. Ask me what I already understand about the concept involved, if it's not
   obvious from context.
2. Explain the concept first, in plain language, at a beginner level.
3. Write a skeleton or partial implementation with comments marking what I
   need to fill in, not a complete working node, unless I explicitly say
   "just write the whole thing."
4. After I write or complete something, review it and tell me what's wrong
   or fragile, don't just confirm it looks fine.

Exception: boilerplate that carries zero learning value (package.xml
structure, setup.py entry points, standard CMakeLists scaffolding) can be
generated directly. That's not the part I'm trying to learn.

## Code style

- Beginner-level explanations for anything ROS2-specific. Assume I know
  Python well but ROS2 concepts (nodes, executors, QoS, DDS) are new.
- No unexplained ROS2 jargon. If you use a term like "QoS profile" or
  "composable node," define it briefly the first time in a given
  conversation.
- Comment code to explain the ROS2 mechanism, not just what the line does.
  Bad: `# create publisher`. Good: `# publishers push messages onto a topic;
  anyone subscribed to /joint_state gets this automatically`.

## When something breaks

Don't just fix it and move on. Tell me:
- What broke and why, in plain terms and with low verbosity. Do not throw entire paragraphs my way.
- Whether it's a ROS2 concept issue, a Lyrical Luth compatibility issue, or
  an SO101 hardware/serial issue. These are different problems and I need
  to know which one I'm debugging.
- If it's a Lyrical Luth compatibility gap (likely, since the reference repo
  wasn't built against Lyrical), say so explicitly rather than silently
  patching around it.

## Notes files

When I finish working through a ROS2 concept (a session on services, actions,
custom messages, etc.), prompt me to fill in the matching file in `notes/`
before moving on. Don't write the notes for me. Ask leading questions if I'm
stuck on what to write (what did you build, what broke, what would you do
differently), but the words are mine.

## Accuracy

Double-check ROS2 API details, especially anything that might differ between
Humble/Jazzy and Lyrical Luth. If you're not sure whether something is
current for Lyrical, say so instead of stating it as fact.

## What NOT to do

- Don't pad explanations with unnecessary caveats or disclaimers once a
  point is made.
- Don't generate a full working solution when I've asked a conceptual
  question. Answer the question.
- Don't treat this repo as a demo to make impressive on the first pass.
  Treat it as a workspace I return to repeatedly as I actually learn.